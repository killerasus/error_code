#include "FlightsErrorCode.h"

namespace
{

struct FlightsErrorCategory : std::error_category
{
    const char* name() const noexcept override;
    std::string message(int ev) const override;
};

const char* FlightsErrorCategory::name() const noexcept
{ return "flights"; }

/**
 * @brief Message associated with the FlightsErrorCode
 * 
 * @param ev 
 * @return std::string 
 */
std::string FlightsErrorCategory::message(int ev) const
{
    switch (static_cast<FlightsErrorCode>(ev))
    {
        case FlightsErrorCode::NonexistentLocations:
            return "nonexistent airport name in request";
        case FlightsErrorCode::DatesInThePast:
            return "request for a date in the past";
        case FlightsErrorCode::InvertedDates:
            return "requested flight return date before departure date";
        case FlightsErrorCode::NoFlightsFound:
            return "no flight combination found";
        case FlightsErrorCode::ProtocolViolation:
            return "received malformed request";
        case FlightsErrorCode::ConnectionError:
            return "could not connect to server";
        case FlightsErrorCode::ResourceError:
            return "insufficient resources";
        case FlightsErrorCode::Timeout:
            return "processing timed out";
        default:
            return "(unrecognized error)";
    }
}

// Instantiation of the FlightsErrorCategory used by make_error_code
const FlightsErrorCategory theFlightsErrorCategory {};

}

// Definition of make_error_code declared in FlightsErrorCode.h
std::error_code make_error_code(FlightsErrorCode e)
{ return {static_cast<int>(e), theFlightsErrorCategory}; }
