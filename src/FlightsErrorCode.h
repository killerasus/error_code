#pragma once

#include <system_error>

enum class FlightsErrorCode
{
  // no 0
  NonexistentLocations = 10, // requested airport doesn't exist
  DatesInThePast,            // booking flight for yesterday
  InvertedDates,             // returning before departure
  NoFlightsFound       = 20, // did not find any combination
  ProtocolViolation    = 30, // e.g., bad XML
  ConnectionError,           // could not connect to server
  ResourceError,             // service run short of resources
  Timeout                   // did not respond in time
};

// Overload of standard library make_error_code for FlightsErrorCode
std::error_code make_error_code(FlightsErrorCode);

namespace std
{
    template<>
    struct is_error_code_enum<FlightsErrorCode> : true_type {};
}
