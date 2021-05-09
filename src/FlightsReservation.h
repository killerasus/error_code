#pragma once

#include "FlightsErrorCode.h"

#include <variant>

// Not the best way to book a flight
struct FlightReservation 
{
	std::string destination;
	int departure{};
};

using Booking = std::variant<FlightReservation, std::error_code>;

/**
 * @brief Tries to book a flight. But you can just fly at 1300 hours and you can't go to Boston
 * 
 * @param destination Don't expect to go to Boston.
 * @param hours Sorry, we can just boo
 * @return tl::expected<FlightReservation, std::error_code> 
 */
inline Booking book_flight(std::string destination, int hours)
{
	if (destination == "Boston")
		return make_error_code(FlightsErrorCode::NonexistentLocations);
	else if (hours != 1300)
		return make_error_code(FlightsErrorCode::NoFlightsFound);
	else
		return FlightReservation{ destination, hours };
}
