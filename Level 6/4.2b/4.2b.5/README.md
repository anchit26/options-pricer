# MOTIVATION

When you use the Stack class and the stack is full or empty when pushing or 
popping an element you get an exception from the Array class. Since the user of 
the Stack class does not know that an Array class is used internally, you don’t 
want that the client must know about the array exceptions. Thus the array 
exception must be translated to a stack exception.