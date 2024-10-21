# Motivation
In this exercise we will make a Stack class. For the data storage we can use the
Array class. Deriving from Array is not a good idea because there is no relation
between Array and Stack. The stack would then inherit indexed operations which 
should not be a functionality of a stack. But we can use the Array class as a 
data member as shown in Figure 4:


Using another class as data member is called composition. In this case the Stack 
class uses internally an Array class. Forwarding functionality to another class is 
called delegation. Here the Stack class delegates the storage of elements to the 
Array class.

# What evolved?
Moved away from using `unsigned int` in array size and indexes.
Started with considering it as a good practice since didn't see a use case for non-
negative numbers. But as in the Stack::Pop function, we might want a negative index
to result in an exception to be thrown. `unsigned int` would result in underflow and
subsequent behaviour would be unexpected.

Upon digging, found that STL classes like vector also DO NOT use unsigned int. 
they use int