#ifndef _JULES_GET_TIME_STRUCT_HPP_
#define _JULES_GET_TIME_STRUCT_HPP_

#include <stdint.h>
#include <chrono>
#include <ctime>

inline constexpr int sec_per_day = 3600 * 24;
inline constexpr int ms_per_day = sec_per_day * 1000;
inline constexpr int days_from_mar_1st_0CE_to_epoch = 719468;
inline constexpr int days_per_quatercentenary = 146097;
inline constexpr int days_per_century = 36524;
inline constexpr int days_per_common_year = 365;
inline constexpr int seconds_per_hour = 3600;
inline constexpr int seconds_per_minute = 60;
inline std::tm getTimeStruct(int time_zone = 0, int64_t time_stamp = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count())
{
    struct tm ret;
    auto seconds_since_epoch = time_stamp + static_cast<int64_t>(time_zone) * seconds_per_hour;
    auto days_since_epoch = (seconds_since_epoch >= 0 ? seconds_since_epoch : seconds_since_epoch - (sec_per_day - 1)) / sec_per_day;
    auto second_of_day = static_cast<int>(seconds_since_epoch - days_since_epoch * sec_per_day);
    int64_t days_since_mar_1st_0CE = days_since_epoch + days_from_mar_1st_0CE_to_epoch;
    int64_t quatercentenaries_since_mar_1st_0CE = (days_since_mar_1st_0CE >= 0 ? days_since_mar_1st_0CE : days_since_mar_1st_0CE - (days_per_quatercentenary - 1)) / days_per_quatercentenary;
    auto day_of_quatercentenary = days_since_mar_1st_0CE - quatercentenaries_since_mar_1st_0CE * days_per_quatercentenary;  // [0, 146096]
    auto year_of_quatercentenary = (day_of_quatercentenary - day_of_quatercentenary / 1460 + day_of_quatercentenary / days_per_century - (day_of_quatercentenary == days_per_quatercentenary - 1)) / days_per_common_year;  // [0, 399]
    auto day_of_year = day_of_quatercentenary - (days_per_common_year * year_of_quatercentenary + year_of_quatercentenary / 4 - year_of_quatercentenary / 100);  // [0, 365]
    auto month_of_year = (5 * day_of_year + 2) / 153;  // [0, 11]
    ret.tm_mday = day_of_year - (153 * month_of_year + 2) / 5 + 1;  // [1, 31]
    ret.tm_mon = (month_of_year + 2) % 12;  // [2, 11] Union [0, 1]
    ret.tm_year = static_cast<int>(year_of_quatercentenary) + static_cast<int>(quatercentenaries_since_mar_1st_0CE * 400) + (ret.tm_mon < 2) - 1900;
    ret.tm_hour = second_of_day / seconds_per_hour;
    ret.tm_min = (second_of_day % seconds_per_hour) / seconds_per_minute;
    ret.tm_sec = (second_of_day % seconds_per_minute);
    return ret;
}

#endif