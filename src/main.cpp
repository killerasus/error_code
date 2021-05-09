#include <iostream>

#include "FlightsReservation.h"

struct BookFlightVisitor {

    void operator()(FlightReservation&& flight)
	{ std::cout << "Booked flight to: " << flight.destination << " at " << flight.departure << std::endl; }

    void operator()(std::error_code&& err)
	{ std::cout << "Couldn't book flight. " << err.message() << std::endl; }

    Booking booking;
};

void book_flight_wrapper(std::string destination, int departure)
{
    std::visit(BookFlightVisitor{}, book_flight(destination, departure));
}

int main(int argc, char** argv)
{
    book_flight_wrapper("Chicago", 1300);
    book_flight_wrapper("Los Angeles", 1700);
    book_flight_wrapper("Boston", 1300);

    return 0;
}
