MB_Framework
============

Framework for Modbus/TCP Gateway


Namespace switching:

Normally the library use C++11 only,
but if the compiler has no C++11 support -> boost fallback.
To activate boost fallback -> define definition at compile time.
Therefore there is a condition around some special includes
and a special namespace constant for each header.
