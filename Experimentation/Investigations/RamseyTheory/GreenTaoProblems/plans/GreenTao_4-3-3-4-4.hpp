// Oliver Kullmann, 16.10.2009 (Swansea)
/* Copyright 2009, 2010 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file Experimentation/Investigations/RamseyTheory/GreenTaoProblems/plans/GreenTao_4-3-3-4-4.hpp
  \brief Investigations on greentao_4(3,3,4,4)

  Aloamo-translation generated by output_greentao_stdname([3,3,4,4],n) or
  output_greentao_sb_stdname([3,3,4,4],n) at Maxima-level, and by
  "GTSat 3 3 4 4 n" at C++ level.

  Standard nested translation generated by
  output_greentao_standnest_stdname([3,3,4,4],n) resp.
  output_greentao_standnest_strong_stdname([3,3,4,4],n).


  \todo Best local search algorithm
  <ul>
   <li>
   Evaluating
   \verbatim
E = eval_ubcsat("GreenTao_4-3-3-4-4_1200.cnf", params=list(runs=100,cutoff=10000),monitor=TRUE)
   \endverbatim
   by plot(E$alg,E$best), there is not enough discrimination (many algorithms
   found solutions in every run). It *seems* however, one can *exclude* gsat,
   gsat_simple, hsat, hwsat, adaptnoveltyp and irots. </li>
   <li>
   Evaluating
   \verbatim
E = eval_ubcsat("GreenTao_4-3-3-4-4_2000.cnf", params=list(runs=100,cutoff=10000),monitor=TRUE)
   \endverbatim
   by plot(E$alg,E$best), the three best algorithms are saps, rsaps and
   sapsnr, with sapsnr as the best (each of the three found solutions,
   while no other algorithm found a solution). </li>
   <li> For n=2500 the cutoff=10000 only yields min=79 (once, with rsaps),
   and perhaps is too low to make some statement here (now rsaps and rots
   look best, with rsaps strongest). </li>
   <li>
   Evaluating
   \verbatim
E = eval_ubcsat("GreenTao_4-3-3-4-4_2500.cnf", params=list(runs=100,cutoff=100000),monitor=TRUE)
   \endverbatim
   by plot(E$alg,E$best), now adaptnoveltyp is best (reaching min=36). At least
   on our problems, for low cutoff alorithms from the saps-family might be
   best, but for harder problems and higher cutoff often adaptnoveltyp is
   by far the best choice. </li>
  </ul>


  \todo greentao_4(3,3,4,4) > 2750
  <ul>
   <li> Assuming adaptnovelty+ is the best algorithm from the Ubcsat-suite.
   </li>
   <li> n=2500
    <ol>
     <li> cutoff=10^6:
     \verbatim
 2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 19 20
 2  1  4  3  9  8  9 16  7  8 10  6  5  5  2  2  1  2
100
     \endverbatim
     Most osteps-values are close to the cutoff, and thus increasing the
     cutoff is important:
     \verbatim
> summary(E$osteps)
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
 808500  929900  967400  954000  984500  999700
     \endverbatim
     </li>
     <li> cutoff=2*10^6 found a solution in the first run (seed=1157186507,
     osteps=1458757). </li>
    </ol>
   </li>
   <li> n=2750
    <ol>
     <li> cutoff=2*10^6:
     \verbatim
13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 30 31 32 33 34 35 39
 1  2  3  7  2  6  8 10 10  5  8  6  4  8  4  3  4  3  2  1  1  1  1
100
> summary(E$osteps)
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
 783600 1609000 1837000 1735000 1937000 1998000
     \endverbatim
     </li>
     <li> cutoff=4*10^6:
     \verbatim
 6  8  9 10 11 12 13 14 15 16 17 18 19 20 24 26 27 28
 1  1  4  7  6  7  8  7  9  5 15 11  6  9  1  1  1  1
100
> summary(E$osteps)
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
1405000 2539000 3257000 3100000 3774000 3999000
     \endverbatim
     </li>
     <li> cutoff=8*10^6:
     \verbatim
 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 19
 2  1  2  4  6  9  9  7  8 14  9  6 10  5  2  4  1  1
100
> summary(E$osteps)
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
2026000 4310000 5894000 5648000 7210000 7995000
     \endverbatim
     </li>
     <li> cutoff=32*10^6 found a solution in run 54 (seed=3641748139,
     osteps=17217403). </li>
    </ol>
   </li>
   <li> n=3000:
    <ol>
     <li> cutoff=2*10^6:
     \verbatim
> ubcsat-okl -alg adaptnovelty+ -runs 100 -cutoff 2000000 -i GreenTao_4-3-3-4-4_3000.cnf -solve | tee GreenTao_4-3-3-4-4_3000.cnf_AUS
> E = read_ubcsat("GreenTao_4-3-3-4-4_3000.cnf_AUS")
42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 66 68 70
 1  1  3  2  3  3  2  5  3  9  7  5  7  4  9  3  5  3  3  8  3  4  1  1  2  1
73 74
 1  1
100
> summary(E$osteps)
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
 782100 1564000 1835000 1701000 1966000 2000000
     \endverbatim
     </li>
     <li> cutoff=4*10^6:
     \verbatim
27 30 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 59
 1  1  1  2  2  1  5  3  8  3  5  8  5  9  8  7  6  7  1  3  1  2  4  1  2  1
60 61 62
 1  1  1
100
> summary(E$osteps)
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
1039000 2735000 3453000 3238000 3823000 3998000
     \endverbatim
     </li>
     <li> cutoff=8*10^6:
     \verbatim
22 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48
 1  1  3  3  2  1  6  5  5  3  6  7  7 10  5 12  6  3  5  2  3  1  1  1  1
100
> summary(E$osteps)
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
2252000 5102000 6445000 6065000 7346000 7994000
     \endverbatim
     </li>
     <li> cutoff=32*10^6:
     \verbatim
> ubcsat-okl -alg adaptnovelty+ -runs 100 -cutoff 32000000 -i GreenTao_4-3-3-4-4_3000.cnf -solve | tee GreenTao_4-3-3-4-4_3000.cnf_AUS2
> E=read_ubcsat("GreenTao_4-3-3-4-4_3000.cnf_AUS2")
22 23 24 25 26 27 28 29 30 33 34
 2  1  1  3  1  1  1  5  2  1  1
19
> summary(E$osteps)
    Min.  1st Qu.   Median     Mean  3rd Qu.     Max.
 4540000 11330000 18840000 18320000 25920000 31400000
     \verbatim
     </li>
     <li> cutoff=100*10^6: 8 runs yield just a minimum of 20, so this
     looks indeed unsatisfiable (or very hard). </li>
     <li> Until now only the aloamo-translation has been considered; now
     investigating the weak standard nested translation with rnovelty+. </li>
     <li> cutoff=4*10^7:
     \verbatim
 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15
 2  2  2  8 12 16 14 15 11  8  2  2  3  2  1
100
     \endverbatim
     So the weak standard nested translation definitely is stronger than
     aloamo. </li>
    </ol>
   </li>
  </ul>

*/

