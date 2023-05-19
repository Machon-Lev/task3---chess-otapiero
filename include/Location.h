#pragma once
struct Location {

public:
    int x;
    int y;

    Location(char x_location, char y_location) 
    {
        x = x_location - 'a';
        y = y_location - '1';
    }
    Location(int x_location, int y_location)
    {
		x = x_location;
		y = y_location;
	}
    Location()
    {
		x = 0;
		y = 0;
	}
   
    bool operator==(const Location& other) const
    {
		return x == other.x && y == other.y;
	}
    bool operator!=(const Location& other) const
    {
        return !(*this == other);
    }

  
};
