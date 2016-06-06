# ADT

What is it?
-----------
Abstract Data Types or ADTs are C++ classes that typically implement a value-like semantic.
They are often corresponding to a physical notion. An important thing about Abstract Data 
Types is that a good ADT is final and contains only Plain Old Data types or PODs, and for that
no pointers or references. Some examples of PODs are integers, floats and doubles. In this case, doubles are used.  
  

Important note 
------------------
As previously stated, these ADTs have doubles as underlying types. 
This could result in unpredictable results for the equality operators (== and !=) due to slight precision errors.
Therefore these operators are not supported for these ADTs. Another reason is that it forces checking whether a
value is within a range rather than exactly equal. Which solves issues where a measurement never gets to the expected 
result due to an ever so slight difference.  
 
Documentation
-------------
The documentation available as of the date of this release is available on
https://roborescue.nl/index.php/Abstract_Data_Types 
this is the most up-to-date documentation on this project
  

