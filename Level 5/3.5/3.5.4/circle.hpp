// circle.hpp
#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"
#include "point.hpp"
#include <string>

namespace AnchitAgarwal
{
	namespace CAD
	{
		/**
		* @brief Represents a circle object in 2D
		*/
		class Circle : public Shape
		{
		private:
			// centre
			Point m_centre;

			// radius
			double m_radius;

		public:

			// Default constructor
			Circle();

			// Parametrized constructor
			Circle(Point, double);

			// Copy constructor
			Circle(const Circle&);

			// Assignment operator
			Circle& operator = (const Circle& source);

			// Destructor
			~Circle();

			// Getters
			const Point& CentrePoint() const;
			double Radius() const;

			// Setters
			void CentrePoint(Point p) { m_centre = p; }
			void Radius(double r) { m_radius = r; }

			// ToString
			std::string ToString() const;

			// Diameter
			double Diameter() const;

			// Area
			double Area() const;

			// Circumference
			double Circumference() const;

			// Send to ostream
			friend std::ostream& operator << (std::ostream& os, const Circle& c);

			// Draw
			void Draw() const;
		};

		// Inline Getters
		inline const Point& Circle::CentrePoint() const
		{
			return m_centre;
		}

		inline double Circle::Radius() const
		{
			return m_radius;
		}
	}
}

#endif // !CIRCLE_HPP