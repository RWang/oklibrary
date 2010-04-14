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


  \todo greentao_3(4) > 4878
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
   <li> n=4879, cutoff=4*10^6 </li>
   <li> n=4881, cutoff=4*10^6: in 8 runs min=1 is attained only twice, so for
   this time let's consider this as unsatisfiable. </li>
   <li> n=4888, cutoff=4*10^6: in 7 runs min=1 is attained only once, so for
   this time let's consider this as unsatisfiable. </li>
   <li> n=4900, cutoff=4*10^6: in 9 runs min=1 is attained only once, so for
   this time let's consider this as unsatisfiable. </li>
   <li> n=5000:
    <ol>
     <li> cutoff=2*10^6 no longer sufficient (in 4 runs only min=10 was
     reached). </li>
     <li> Also with cutoff=4*10^6 in 6 runs only min=9 was reached. </li>
     <li> So let's consider this (for now) as unsatisfiable. </li>
    </ol>
   </li>
  </ul>
  
*/
