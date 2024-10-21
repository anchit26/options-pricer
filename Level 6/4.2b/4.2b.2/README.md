
# Self notes

## Generic inheritance idea and motivation
Derived generic class can and mostly should use base class functionalities which are 
present in base class already.

All new "specialised" functionalities should be defined and implemented by the derived
class which limits the generic conusmption of the Base class.

In this example, Array, the base class does basic things which a canonical class 
might do. Specialised functionality like `+ operator`,  `* operator`, dot product,
are all defined by NumericalArray, the derived class.

Interesting!!!
