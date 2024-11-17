#pragma once
#include <iostream>
using namespace std;

class Request
{
	int RequestTime;
	int distance;
	int severity;

public:
	Request(int RequestTime, int distance) : Request(RequestTime, distance, 0) {}
	Request(int RequestTime, int distance, int severity) : RequestTime(RequestTime), distance(distance), severity(severity) {}

	// getters
	int getRequestTime() { return RequestTime; }
	int getDistance() { return distance; }
	int getSeverity() { return severity; }

	// stream insertion operator
	friend std::ostream& operator<<(std::ostream& os, Request& r)
	{
		os << r.getSeverity();
		return os;
	}
	/*
	bool operator< (Request& r2) { return getSeverity() < r2.getSeverity(); }
	bool operator> (Request& r2) { return getSeverity() > r2.getSeverity(); }
	bool operator<=(Request& r2) { return getSeverity() <= r2.getSeverity(); }
	bool operator>=(Request& r2) { return getSeverity() >= r2.getSeverity(); }
	bool operator==(Request& r2) { return getSeverity() == r2.getSeverity(); }
	bool operator!=(Request& r2) { return getSeverity() != r2.getSeverity(); }
	*/
};

// comparison operators (based on severity)


bool operator< (Request r1, Request r2) { return r1.getSeverity() < r2.getSeverity(); }
bool operator> (Request r1, Request r2) { return r1.getSeverity() > r2.getSeverity(); }
bool operator<=(Request r1, Request r2) { return r1.getSeverity() <= r2.getSeverity(); }
bool operator>=(Request r1, Request r2) { return r1.getSeverity() >= r2.getSeverity(); }
bool operator==(Request r1, Request r2) { return r1.getSeverity() == r2.getSeverity(); }
bool operator!=(Request r1, Request r2) { return r1.getSeverity() != r2.getSeverity(); }
