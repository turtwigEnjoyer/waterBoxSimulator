#pragma once

/*
    4.3 SIM PROCESSING
    4.3.1 Check if block is right. Else reposition for each particle --> Do this in grid
    4.3.2
        set density to 0
        set acceleration to g

        Densities increase
        Ap = (h^2 - mod^2)^3
        apply Ap to both

 
        Density lin transform
        pi = (pi +h^6)* 21/64* (15* m/(pi* h^9))

        Acceleration transfer
        If distance is close enough, compute acceleration
    4.3.3
        Collisions with bounds
    4.34 all particles updated
*/   