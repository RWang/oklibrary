// Oliver Kullmann, 12.4.2010 (Swansea)
/* Copyright 2010 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file Experimentation/Investigations/RamseyTheory/GreenTaoProblems/plans/GreenTao_3-4-4-k.hpp
  \brief On investigations into Green-Tao numbers greentao_3(4,4,k)

  Aloamo-translations are generated by output_greentao_stdname([4,4,k],n) at
  Maxima-level, and by "GTSat 4 4 k n" at C++ level.

  Standard nested translations are generated by
  output_greentao_standnest_stdname([4,4,k],n) resp.
  output_greentao_standnest_strong_stdname([4,4,k],n).


  \todo greentao_3(4) > 5200
  <ul>
   <li> Let's start with the weak standard nested translation and with
   rnovelty+. </li>
   <li> greentao_2(4) = 512. </li>
   <li> n=1000 is satisfiable in 205 steps. </li>
   <li> n=1500 is satisfiable in 404 steps. </li>
   <li> n=2000 is satisfiable in 1050 steps. </li>
   <li> n=2500 is satisfiable in 1339 steps. </li>
   <li> n=3000 is satisfiable in 2831 steps. </li>
   <li> n=3500 is satisfiable in 6780 steps (seems hard for OKsolver_2002,
   and also for minisat2). </li>
   <li> n=4000 is satisfiable in 26560 steps. </li>
   <li> n=4500: cutoff=300000 finds a solution in the second run. </li>
   <li> n=4800: cutoff=2*10^6: in run 2 a solution was found (seed=2960182613,
   osteps=1914331). </li>
   <li> n=4850, cutoff=4*10^6: in run 3 a solution was found (seed=914035932,
   osteps=3424650). </li>
   <li> n=4875, cutoff=4*10^6: in run 5 a solution was found (seed=2573294237,
   osteps=3164363). </li>
   <li> n=4878, cutoff=4*10^6: in run 4 a solution was found (seed=2807257037,
   osteps=3921866). </li>
   <li> n=4879, cutoff=4*10^6: in run 2 a solution was found (seed=1576343301,
   osteps=2941962).  </li>
   <li> n=4880, cutoff=4*10^6: in run 18 a solution was found (seed=865787531,
   osteps=1866108). </li>
   <li> n=4881, cutoff=4*10^6: in run 6 a solution was found (seed=4090407979,
   osteps=2922175). </li>
   <li> n=4888, cutoff=4*10^6: in run 1 a solution was found (seed=899655214,
   osteps=3135106). </li>
   <li> n=4900, cutoff=4*10^6: in run 14 a solution was found (seed=4066642292,
   osteps=2874713). </li>
   <li> n=4920, cutoff=4*10^6: in run 6 a solution was found (seed=1123326814,
   osteps=2867343). </li>
   <li> n=4940, cutoff=4*10^6:
   \verbatim
 0  2  3  4  5  6  7  8  9 10 11 12
 1  5  8  9  9 11 11  8  1  1  3  4
71
   \endverbatim
   Peculiar, that here min=1 was not reached at all (a similar pattern was
   also observed for smaller n). </li>
   <li> n=4960, cutoff=4*10^6:
   \verbatim
 0  2  3  4  5  6  7  8  9 10 11 12 13 14 15
 1  2  2  3  5  7  3  1  1  3  2  1  3  1  1
36
   \endverbatim
   (seed=2637190941, osteps=3082622). </li>
   <li> n=4980
    <ol>
     <li> cutoff=4*10^6:
     \verbatim
 2  3  4  5  6  7  8  9 10 11 12 13 14 15 16
 4  6  6  7 19 10  7 11  6  7  8  4  1  2  2
100
     \endverbatim
     </li>
     <li> cutoff=6*10^6: in run 34 a solution was found (seed=3797733747,
     osteps=4589183). </li>
    </ol>
   </li>
   <li> n=5000:
    <ol>
     <li> cutoff=2*10^6 no longer sufficient (in 4 runs only min=10 was
     reached). </li>
     <li> Also with cutoff=4*10^6 in 6 runs only min=9 was reached. </li>
     <li> cutoff=6*10^6: in run 12 a solution was found (seed=480226455,
     osteps=4944068). </li>
    </ol>
   </li>
   <li> n=5025, cutoff=6*10^6: In run 79 a solution was found:
   \verbatim
 0  1  2  3  4  5  6  7  8  9 10 11 13 14 16 17 18 20
 1  2  4  2  8  6 12 11  7  6  3  5  2  5  1  1  2  1
79
   \endverbatim
   </li>
   <li> n=5037, cutoff=6*10^6: In run 11 a solution was found (seed=1166271130,
   osteps=4644862). </li>
   <li> n=5038, cutoff=6*10^6: In run 4 a solution was found (seed=1817616388,
   osteps=4885226). </li>
   <li> n=5039
    <ol>
     <li> cutoff=6*10^6:
     \verbatim
 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 17
 2  4  6  9  4  7 12 10 14  8  7  4  5  3  4  1
100
     \endverbatim
     </li>
     <li> cutoff=8*10^6: In run 4 a solution was found (seed=3337162132,
     osteps=7422949). </li>
     </li
    </ol>
   </li>
   <li> n=5040
    <ol>
     <li> cutoff=6*10^6:
     \verbatim
 1  3  4  5  6  7  8  9 10 11 12 13 14 15 16 18 21
 3  4  9  7 12  8  7  9  8 13  6  4  1  3  4  1  1
100
     \endverbatim
     </li>
     <li> cutoff=8*10^6: In run 73 a solution was found (seed=1520163615,
     osteps=2557823). </li>
    </ol>
   </li>
   <li> n=5044
    <ol>
     <li> cutoff=6*10^6
     \verbatim
 1  2  3  4  5  6  7  8  9 10 11 12 13 15 16 21 22
 2  1  5  5  9 11  4 14  6 14 11  5  4  3  4  1  1
100
     \endverbatim
     </li>
     <li> cutoff=8*10^6: In run 18 a solution was found (seed=3627982560,
     osteps=5531534). </li>
    </ol>
   </li>
   <li> n=5050:
    <ol>
     <li> cutoff=6*10^6:
     \verbatim
 2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 19 22
 2  5  6 11  6 15  5  6 14  6  3  4  6  4  3  2  1  1
100
     \endverbatim
     </li>
     <li> cutoff=8*10^6:
     \verbatim
 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17
 3  5  4  9  9 17 10 10 13  3  4  3  3  4  1  1  1
100
     \endverbatim
     In another 53 runs a solution was found (seed=4228182136,
     osteps=5806766). </li>
    </ol>
   </li>
   <li> n=5100:
    <ol>
     <li> cutoff=6*10^6:
     \verbatim
 4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 23 24
 4  5  1  5  7 12  7  8  5  8  9  3  4  4  3  7  3  3  1  1
100
     \endverbatim
     </li>
     <li> cutoff=8*10^6:
     \verbatim
 2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 19 20
 6  3  3  2  8 10  6 13  7  8  8  9 10  2  1  1  2  1
100
     \endverbatim
     </li>
     <li> cutoff=10^7:
     \verbatim
 1  3  4  5  6  7  8  9 10 11 12 13 14 15 17 19
 1  1  6 12 10 11  9 11 11 10  6  2  3  4  2  1
100
     \endverbatim
     </li>
     <li> cutoff=12*10^6: Found a solution in run 21 (seed=3386167483,
     osteps=11712754). </li>
    </ol>
   </li>
   <li> n=5200, cutoff=12*10^6: In run 70 a solution was found
   (seed=918366649, osteps=10327030). The second lowest min-value was 4
   (attained once). </li>
   <li> n=5300, cutoff=12*10^6 </li>
  </ul>
  
*/
