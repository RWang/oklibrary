// Oliver Kullmann, 11.10.2009 (Swansea)
/* Copyright 2009, 2010 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file Experimentation/Investigations/RamseyTheory/GreenTaoProblems/plans/GreenTao_4-3-3-3-4.hpp
  \brief Investigations on greentao_4(3,3,3,4)

  Boolean problems using the aloamo-translation are generated by
  output_greentao_stdname([3,3,3,4],n) or
  output_greentao_sb_stdname([3,3,3,4],n) at Maxima-level, and by
  "GTSat 3 3 3 4 n" at C++ level.

  Boolean problems using the standard nested translation are generated by
  output_greentao_standnest_stdname([3,3,3,4],n) at Maxima-level.


  \todo Best local search algorithm
  <ul>
   <li>
   Evaluating
   \verbatim
E = eval_ubcsat("GreenTao_4-3-3-3-4_800.cnf", params=list(runs=100,cutoff=10000),monitor=TRUE)
   \endverbatim
   by plot(E$alg,E$best), the best algorithms seems sapsnr. </li>
   <li> However, considering n=1000, now gsat-tabu, adaptnovelty+, rots and
   samd seem best (for cutoff=10000), while sapsnr became rather weak! </li>
   <li> Testing these four algorithms with cutoff=10^6:
   \verbatim
E = eval_ubcsat("GreenTao_4-3-3-3-4_1000.cnf", params=list(runs=100,cutoff=1000000),monitor=TRUE, algs=list(gsat_tabu="gsat-tabu", adaptnoveltyp="adaptnovelty+", rots="rots", samd="samd"))
   \endverbatim
   (currently algorithms-names are inappropriately handled by eval_ubcsat):
   adaptnovelty+ is clearly best: the best min(=6), and a very small spread;
   the second is samd, but with worst min, and a far larger spread. </li>
  </ul>


  \todo Lower bounds: greentao_4(3,3,3,4) > 1050
  <ul>
   <li> n=800 easily found satisfiable by sapsnr (cutoff=10*10^3,
   runs=100). </li>
   <li> n=850
    <ol>
     <li> cutoff=10^4: adaptnovelty+ reaches in 100 runs min=17
     (while sapsnr reaches min=12, and samd reaches min=15). </li>
     <li> cutoff=10^5: adaptnovelty+ reaches in 100 runs min=1, while sapsnr
     finds a solution in run 31 (seed=1051937617). </li>
    </ol>
   </li>
   <li> n=900
    <ol>
     <li> cutoff=10^4: adaptnovelty+ reaches in 100 runs min=22
     (while sapsnr reaches min=29, and samd reaches min=22). </li>
     <li> cutoff=10^5: adaptnovelty+ reaches in 100 runs min=3
     (while sapsnr reaches min=21, and samd reaches min=5). </li>
     <li> cutoff=10^6: adaptnovelty+ finds a solution in run 2
     (seed=446607350). </li>
    </ol>
   </li>
   <li> n=950
    <ol>
     <li> cutoff=10^6, using adaptnovelty+: reaches min=1 (median=4,
     mean=4.3). </li>
     <li> cutoff=10^7 (adaptnovelty+): found a solution in run 3
     (seed=3537296603). </li>
    </ol>
   </li>
   <li> n=975
    <ol>
     <li> cutoff=10^7 (adaptnovelty+): A solution was found in run 60
     (seed=839702132, osteps=9609423). </li>
    </ol>
   </li>
   <li> n=988
    <ol>
     <li> cutoff=10^7 (adaptnovelty+): A solution was found in run 19
     (seed=825817361, osteps=8785207). </li>
    </ol>
   </li>
   <li> n=989
    <ol>
     <li> cutoff=10^7 (adaptnovelty+):
     \verbatim
 1  2  3  4  5  6  7
 2 14 22 30 21  9  2
100
     \endverbatim
     </li>
     <li> cutoff=2*10^7 (adaptnovelty+):
     \verbatim
 1  2  3  4  5  6
 4 32 45 14  4  1
100
     \endverbatim
     </li>
     <li> cutoff=8*10^7 (adaptnovelty+) finds a solution in run 9
     (seed=3728380835, osteps=58003122). </li>
    </ol>
   </li>
   <li> n=990: cutoff=8*10^7 finds a solution in run 76 (seed=2964724610,
   osteps=19062436). </li>
   <li> n=991
    <ol>
     <li> cutoff=10^7 (adaptnovelty+):
     \verbatim
 1  2  3  4  5  6  7
 1  8 21 28 30  8  4
100
     \endverbatim
     </li>
     <li> cutoff=8*10^7 (adaptnovelty+):
     \verbatim
 1  2  3  4
18 68 13  1
100
     \endverbatim
     </li>
     <li> cutoff=16*10^7 (adaptnovelty+): finds a solution in run 5 (seed=
     2464081211, osteps=118475284). </li>
    </ol>
   </li>
   <li> n=994
    <ol>
     <li> cutoff=10^7 (adaptnovelty+):
     \verbatim
> ubcsat-okl -alg adaptnovelty+ -cutoff 10000000 -runs 100 -solve -i GreenTao_4-3-3-3-4_994.cnf | tee GreenTao_4-3-3-3-4_994.cnf_OUT
 1  2  3  4  5  6  7  8
 1  2 13 20 37 18  7  2
     \endverbatim
     </li>
     <li> Checking all algorithms with cutoff=10^6:
     \verbatim
> E = eval_ubcsat("GreenTao_4-3-3-3-4_994.cnf", params=list(runs=100,cutoff=1000000),monitor=TRUE)
     \endverbatim
     The best algorithms seem to be gwsat, gsat_tabu, adaptnoveltyp and samd,
     with adaptnoveltyp clearly best (reaching also the best min=6). </li>
     <li> cutoff=16*10^7 (adaptnovelty+): finds a solution in run 7 (seed=
     2045601853, osteps=122505356). </li>
    </ol>
   </li>
   <li> n=995
    <ol>
     <li> cutoff=16*10^7 (adaptnovelty+):
     \verbatim
 1  2  3
25 74  1
100
> summary(E$osteps)
     Min.   1st Qu.    Median      Mean   3rd Qu.      Max.
  3958000  31940000  57640000  63860000  88740000 159400000
     \endverbatim
     </li>
     <li> cutoff=32*10^7 (adaptnovelty+): found a solution in run 93
     (seed=3734716363, osteps=136285731). </li>
     </li>
    </ol>
   </li>
   <li> n=996: with cutoff=32*10^7 adaptnovelty+ found a solution in run 81
   (seed=3070906952, osteps=244941203). </li>
   <li> n=997: cutoff=32*10^7 (adaptnovelty+) found a solution in run 20
   (seed=2765449941, osteps=202286569). </li>
   <li> n=998
    <ol>
     <li> cutoff=32*10^7 (adaptnovelty+):
     \verbatim
> E = read_ubcsat("GreenTao_4-3-3-3-4_998.cnf_OUT");
 1  2
14 37
51
> summary(E$osteps)
     Min.   1st Qu.    Median      Mean   3rd Qu.      Max.
  3491000  46060000  74970000 107200000 146400000 276500000

> ubcsat-okl -alg adaptnovelty+ -runs 500 -cutoff 320000000 -i GreenTao_4-3-3-3-4_998.cnf | tee GreenTao_4-3-3-3-4_998.cnf_OUT
> E2 = read_ubcsat("GreenTao_4-3-3-3-4_998.cnf_OUT")
  0   1   2   3
  2 171 323   4
500
> summary(E2$osteps)
     Min.   1st Qu.    Median      Mean   3rd Qu.      Max.
  3559000  52810000  90070000 111600000 155000000 313400000
     \endverbatim
     (best solution: seed=2845522946, osteps=48802626). </li>
    </ol>
   </li>
   <li> n=999: cutoff=32*10^7 (adaptnovelty+) found 3 solutions in 65 runs
   (seed=3665124127, osteps=129828231). </li>
   <li> n=1000
    <ol>
     <li> cutoff=10*10^3 with 100 runs reaches only min=68 (sapsnr), while
     using cutoff=100*10^3 we get min=65, so let's assume for now that it's
     unsatisfiable. </li>
     <li> However, using adaptnovelty+ with cutoff=100*10^3 we reach min=17,
     so here adaptnovelty+ is much better! </li>
     <li> cutoff=10^6: adaptnovelty+ reaches in 100 runs min=4
     (while sapsnr reaches min=50, and samd reaches min=8). </li>
     <li> cutoff=10^7 (adaptnovelty+): reaches in 100 runs min=1 (where
     median=5 and mean=5.01). </li>
     <li> cutoff=10^8 (adaptnovelty+):
     \verbatim
> ubcsat-okl -alg adaptnovelty+ -cutoff 100000000 -runs 100 -solve -i GreenTao_4-3-3-3-4_1000.cnf | tee GreenTao_4-3-3-3-4_1000.cnf_OUT
 1  2  3  4
 6 51 40  3
     \endverbatim
     </li>
     <li> cutoff=16*10^7 (adaptnovelty+):
     \verbatim
 1  2  3
14 74 12
100
> summary(E$osteps)
     Min.   1st Qu.    Median      Mean   3rd Qu.      Max.
  4633000  36250000  57420000  66770000  93560000 156800000
     \endverbatim
     </li>
     <li> cutoff=32*10^7 (adaptnovelty+): in 103 runs one solution was
     found (seed=1507582452, osteps=21453179). </li>
    </ol>
   </li>
   <li> n=1001, cutoff=32*10^7 (adaptnovelty+): in 132 runs one solution was
   found (seed=348166976, osteps=247927263). </li>
   <li> n=1002, cutoff=5*10^8  (adaptnovelty+): in 62 runs one solution was
   found (seed=599457750, osteps=71235234). </li>
   <li> n=1003, cutoff=5*10^8  (adaptnovelty+): in 18 runs one solution was
   found (seed=3062595810, osteps=481408747). </li>
   <li> n=1004, cutoff=5*10^8  (adaptnovelty+): in 243 runs one solution was
   found (seed=3799196791, osteps=499062687). It seems the cutoff should
   be increased. </li>
   <li> n=1005, cutoff=10^9 (adaptnovelty+): in 26 runs one solution was
   found (seed=425251625, osteps=922264601). </li>
   <li> n=1006, cutoff=10^9 (adaptnovelty+): in 29 runs two solutions were
   found (seed=1667268345, osteps=342601286). </li>
   <li> n=1010, cutoff=10^9 (adaptnovelty+): in 91 runs one solution was found
   (seed=4034341891, osteps=669592854). </li>
   <li> n=1015
    <ol>
     <li> Using the standard nested translation, with cutoff=10^7: In 317
     runs one solution was found (seed=548029005, osteps=8867169):
     \verbatim
 0  1  2  3  4  5  6  7  8
 1  8 30 71 76 66 48 16  1
317
     \endverbatim
     </li>
    </ol>
   </li>
   <li> n=1020
    <ul>
     <li> aloamo
      <ol>
       <li> cutoff=10^9 (aloamo, adaptnovelty+)
       \verbatim
  1   2   3
 18 227 111
356
  1   2   3   4
 17 222 126   2
367
       \endverbatim
       </li>
      </ol>
     </li>
     <li> Weak standard nested translation
      <ol>
       <li> adaptnovelty+, cutoff=10^7:
       \verbatim
  1   2   3   4   5   6   7   8   9  10
  4  26  59 110 136  95  46  21   2   1
500
       \endverbatim
       </li>
       <li> sapsnr, cutoff=10^7:
       \verbatim
 44  46  47  48  49  50  51  52  53  54  55  56
  1   8  12  21  30  52  76 114  70  69  36  11
500
       \endverbatim
       </li>
       <li> Best local search algorithm, evaluating
       \verbatim
E = eval_ubcsat("GreenTao_N_4-3-3-3-4_1020.cnf", params=list(runs=200,cutoff=1000000))
       \endverbatim
       by plot(E$alg,E$best):
       \verbatim
> table(E$best[E$alg=="rnoveltyp"])
 2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18
 2  6  8 10 20 22 15 21 25 17 21 13 10  4  3  2  1
> table(E$best[E$alg=="novelty"])
 2  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 
 1  2  1  2  5  5  6 11  8  8 11 13 16 11 16 10 18 16  5 13  7  4  2  6  1  1
30
 1
> table(E$best[E$alg=="walksat_tabu_nonull"])
 5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
 1  2  4  8 15 23 29 23 32 27 18 12  2  3  1
> table(E$best[E$alg=="walksat_tabu"])
 5  6  7  8  9 10 11 12 13 14 15 16 17
 2  2  3  5 13 32 28 34 20 22 22 12  5
> table(E$best[E$alg=="adaptnoveltyp"])
 7  8  9 10 11 12 13 14 15 16 17 18 19 21
 1  1  3  7 21 26 38 28 31 20 11  9  3  1
> table(E$best[E$alg=="noveltyp"])
 8 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 34 35
 1  1  2  3  2  5  9  9  7  7  6  8  8  8 13 16 14  5 18 14 14  7  7  4  4  1
36 38 39 40
 3  2  1  1
> table(E$best[E$alg=="gwsat"])
10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
 2  5  1  3  9  9 19 25 28  9 40 15 14  9  8  1  3

       \endverbatim
       </li>
       <li> rnoveltyp, cutoff=10^7 found a solution in run 14
       (seed=1890651975, osteps=8736133). </li>
      </ol>
     </li>
     <li> Strong standard nested translation
      <ol>
       <li> adaptnovelty+, cutoff=10^7:
       \verbatim
  4   5   6   7   8   9  10  11  12
 15  46  94 120 115  81  21   6   2
500
       \endverbatim
       </li>
       <li> Best local search algorithm, evaluating
       \verbatim
E = eval_ubcsat("GreenTao_SN_4-3-3-3-4_1020.cnf", params=list(runs=200,cutoff=1000000))
       \endverbatim
       by plot(E$alg,E$best):
       \verbatim
> table(E$best[E$alg=="rnoveltyp"])
 5  8  9 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29
 1  2  5  6  8 10 13 11 15 21 14 15 13 19  9 10 10  8  7  1  1  1
> table(E$best[E$alg=="adaptnoveltyp"])
 7  9 10 11 12 13 14 15 16 17 18 19 21
 1  4  7 20 27 37 31 26 25 12  5  4  1
> table(E$best[E$alg=="gwsat"])
 8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 26 29
 2  3  2  2  8  9 19 20 21 27 29 25 17  9  3  1  1  1  1
> table(E$best[E$alg=="rnovelty"])
 8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 29 30
 1  3  3  3  7  7 14 13 19 18 19 16 18 10 11  7 13  9  2  3  3  1
> table(E$best[E$alg=="walksat_tabu"])
14 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35
 1  1  1  4  1 10 17 16 21 21 21 30 14 12 20  5  4  1
       \endverbatim
       </li>
       <li> rnoveltyp, cutoff=10^7: in 12 runs only a min=6 was reached, so
       it seems inferior to the weak nested translation. </li>
      </ol>
     </li>
    </ul>
   </li>
   <li> n=1025
    <ol>
     <li> Weak standard nested translation, rnovelty+, cutoff=10^7:
     \verbatim
> E=read_ubcsat("GreenTao_N_4-3-3-3-4_1025.cnf_OUT")
 0  1  2  3  4  5  6  7  8
 1  7 26 53 80 52 29  8  1
257
> E[E$min==0,]
    sat min  osteps  msteps       seed
257   1   0 2471159 2471159 4183213878
     \endverbatim
     </li>
     <li> Same, but with cutoff=2*10^7:
     \verbatim
 0  2  3  4  5  6
 1 10 28 23  6  1
69
> E[E$min==0,]
   sat min  osteps  msteps      seed
69   1   0 7048847 7048847 838582080
     \endverbatim
     </li>
    </ol>
   </li>
   <li> n=1030
    <ol>
     <li> Weak standard nested translation, rnovelty+, cutoff=10^7:
     \verbatim
  1   2   3   4   5   6   7   8   9
  6  21  60 119 103 112  51  21   7
500
     \endverbatim
     </li>
     <li> Weak standard nested translation, rnovelty+, cutoff=2*10^7:
     \verbatim
  1   2   3   4   5   6   7
 20  67 130 162  89  26   6
500
     \endverbatim
     </li>
     <li> Weak standard nested translation with sapsnr and cutoff=4*10^7 only
     reached min=46. </li>
     <li> Weak standard nested translation, rnovelty+, cutoff=8*10^7: found
     a solution in run 29 (seed=927551785, osteps=14114027). </li>
     <li> Strong nested standard translation: Evaluating
     \verbatim
E = eval_ubcsat("GreenTao_SN_4-3-3-3-4_1030.cnf", params=list(runs=200,cutoff=1000000))
     by plot(E$alg,E$best):
     \verbatim
> table(E$best[E$alg=="rnoveltyp"])
 8  9 10 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34
 1  1  2  2  1  2  5  5 12  8  8 10 15 20 21 13 13 16 12 13  5  5  3  2  2  2
35
 1
> table(E$best[E$alg=="rnovelty"])
 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 34
 1  3  1  4  1  4  2 11 10  9 13  8 14 19 17 14 11 12 13  8 12  7  3  2  1
> table(E$best[E$alg=="adaptnoveltyp"])
10 11 12 13 14 15 16 17 18 19 20 21 22 23
 4  1 13 11 26 35 33 29 22  9 11  4  1  1
> table(E$best[E$alg=="gwsat"])
11 13 14 15 16 17 18 19 20 21 22 23 24 25 26
 2  6  9 13 21 23 22 22 29 18 12  7  7  5  4
     \endverbatim
     So also here seems rnovelty+ best. </li>
     <li> Strong nested standard translation, saps, cutoff=2*10^7:
     \verbatim
40 45 46 47 48 49 50 51 52 53 54
 1  2  5  5 15 17 25 25 23 16  3
137
     \endverbatim
     </li>
     <li> Strong nested standard translation, rnovelty+, cutoff=2*10^7:
     \verbatim
 5  6  7  8  9 10 11 12 13 14 15 16 17 18
 2  5 10 16 27 26 23 15 12 16  9  8  1  2
172
     \endverbatim
     Thus the weak nested translation seems better than the strong. </li>
     <li> Logarithmic translation: Evaluating
     \verbatim
E = eval_ubcsat("GreenTao_L_4-3-3-3-4_1030.cnf", params=list(runs=200,cutoff=1000000))
     \endverbatim
     by plot(E$alg,E$best):
     \verbatim
> table(E$best[E$alg=="adaptnoveltyp"])
 8  9 10 11 12 13 14 15 16 17 18 19 20 21
 2  1  5  5 24 19 36 32 26 21 15  7  6  1
> table(E$best[E$alg=="gwsat"])
 9 10 11 12 13 14 15 16 17 18 19 20 21 22
 5  3  4 20 26 25 19 27 26 23  9  8  4  1
     \endverbatim
     It seems the weak nested translation is superior. </li>
     <li> Logarithmic translation, rnovelty+, cutoff=10^7:
     \verbatim
12 15 16 17 18 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40
 1  3  1  2  3  4  4  3  2  9  2  8  6 15 12 16 25 10 24 23 20 26 36 22 24 21
41 42 43 44 45
 9  8  3  1  1
344
     \endverbatim
     And cutoff=2*10^7:
     \verbatim
 8 13 14 15 16 17 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38
 1  1  3  1  1  1  2  2  1  4  3  7  8  5 12 11  7  1 13 13  8 10 17 16  6  9
39
 7
170
     \endverbatim
     </li>
     <li> Logarithmic translation, adaptnovelty+, cutoff=10^7:
     \verbatim
 2  3  4  5  6  7  8  9 10 11 13
 1  2  3 20 30 72 90 65 33 15  1
332
  3   4   5   6   7   8   9  10  11  12
  3   9  26  58 106 107  93  77  18   3
500
     \endverbatim
     and with cutoff=2*10^7:
     \verbatim
 2  3  4  5  6  7  8  9 10 11
 1  7 19 53 84 92 68 35  3  1
363
     \endverbatim
     while rnovelty+ with cutoff=4*10^7 achieves
     \verbatim
 4  8 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33
 1  1  1  1  2  2  3  2  3  7  4  2  4  6  6 11  9 12 10 26 24 18 19 26 20 19
34 35 36 37 39
 8  8  2  2  2
261
     \endverbatim
     </li>
     <li> So definitely the weak standard nested translation is superior. </li>
     <li> Weak standard reduced translation: Evaluating
     \verbatim
E = eval_ubcsat("GreenTao_R_4-3-3-3-4_1030.cnf", params=list(runs=200,cutoff=1000000))
     \endverbatim
     by plot(E$alg,E$best) and eval_ubcsat_dataframe(E):
     \verbatim
adaptnoveltyp :
 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
 4  3  9 10 12 16 30 35 28 27 14  8  2  1  1
gwsat :
 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24
 1  1  7  8  9 25 21 22 31 24 23  9  9  6  3  1
     \endverbatim
     </li>
     <li> Strong standard reduced translation: Evaluating
     \verbatim
E = eval_ubcsat("GreenTao_SR_4-3-3-3-4_1030.cnf", params=list(runs=200,cutoff=1000000))
     \endverbatim
     by plot(E$alg,E$best) and eval_ubcsat_dataframe(E):
     \verbatim
adaptnoveltyp :
 8  9 10 11 12 13 14 15 16 17 18 19 20 21 22
 1  2  2 11 15 18 25 20 37 25 20 12  6  3  3
gwsat :
11 12 13 14 15 16 17 18 19 20 21 22 23 24
10  6  7 10 22 34 20 27 15 17 13 12  4  3
rnovelty :
13 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42
 1  2  2  1  3  3  3  2  7  5  2  6 10 13  9 11  9 11  9 14 14  8  9 12  4  7
     \endverbatm
     </li>
     <li> Strong standard reduced translation, adaptnovelty+, cutoff=10^7:
     \verbatim
  4   5   6   7   8   9  10  11  12  13  14
  2   4  13  42  77 106 102 100  40  11   3
500
     \endverbatim
     </li>
    </ol>
   </li>
   <li> n=1040, weak standard nested translation
    <ol>
     <li> rnovelty+: finds a solution with cutoff=8*10^7 in run 96
     (seed=4254844099, osteps=39626357) (while 255 runs with
     cutoff=4*10^8 only obtained min=1 three times). </li>
     <li> adaptnovelty+: with cutoff=8*10^7 in 83 runs only min=2 was
     reached. </li>
    </ol>
   </li>
   <li> n=1050, rnovelty+, cutoff=8*10^7: finds in 293 runs one solution
   (seed=2097534984, osteps=68769314); another 232 runs:
   \verbatim
 2  3  4  5  6  7  8  9
 7 25 75 75 36 10  3  1
232
   \endverbatim
   while cutoff=16*10^7 yields:
   \verbatim
 1  2  3  4  5  6  7
 2  7 36 50 17  2  1
115
   \endverbatim
   and cutoff=32*10^7:
   \verbatim
 1  2  3  4  5
 5 29 83 44  4
165
   \endverbatim
   </li>
   <li> n=1051, rnovelty+
    <ol>
     <li> cutoff=32*10^7:
     \verbatim
 2  3  4  5
 4 16 13  1
34
     \endverbatim
     </li>
     <li> cutoff=64*10^7:
     \verbatim
1 2 3
1 7 8
16
1 2 3
1 2 3
6
     \endverbatim
     </li>
    </ol>
   </li>
   <li> n=1055
    <ol>
     <li> rnovelty+, cutoff=16*10^7:
     \verbatim
  1   2   3   4   5   6   7   8
  3  13  59 134 107  52  13   1
382
     \endverbatim
     </li>
    </ol>
   </li>
   <li> n=1060
    <ol>
     <li> rnovelty+, cutoff=8*10^7:
     \verbatim
  2   3   4   5   6   7   8   9  10  11  12
  2  13  36  90 107 116  85  33  15   2   1
500
     \endverbatim
     while cutoff=16*10^7 yields
     \verbatim
  2   3   4   5   6   7   8   9  10
  4  38 103 142  72  53  20   3   2
437
 2  3  4  5  6  7  8
 1 10 27 42 26 10  3
119
     \endverbatim
     and cutoff=32*10^7 yields
     \verbatim
 2  3  4  5  6  7
 3 12 22 17  4  1
59
 1  2  3  4  5  6
 1  1  1 13  6  1
23
     \endverbatim
     </li>
    </ol>
   </li>
  </ul>

*/

