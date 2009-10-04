// Oliver Kullmann, 2.10.2009 (Swansea)
/* Copyright 2009 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file Experimentation/Investigations/Groupoids/plans/Transformations.hpp
  \brief On investigations regarding transformation semigroups


  \todo Hypergraph transformations I
  <ul>
   <li> Consider a natural number n >= 0, N = {1,...,n}, the powerset P =
   powerset(P), and the set MS_n =powerset(P) of all set-systems on N. </li>
   <li> Let c_0: MS -> MS be direct complementation: c_0(S) = P - S. </li>
   <li> Let c_1: MS -> MS be elementwise complementation: c_1(S): c_1(S) =
   { N - T : T in S }. </li>
   <li> Let s: MS -> MS be the closure under subsumption: s(S) = union_{T in S}
   powerset(T). </li>
   <li> What is the closure of {c_0, c_1, s} under composition? </li>
   <li>
   \verbatim
oklib_include("OKlib/ComputerAlgebra/Algebra/Lisp/Groupoids/Closures.mac")$
oklib_include("OKlib/ComputerAlgebra/Algebra/Lisp/Groupoids/Semigroups/TransformationMonoids.mac")$
oklib_include("OKlib/ComputerAlgebra/Hypergraphs/Lisp/SetSystems.mac")$
oklib_include("OKlib/ComputerAlgebra/DataStructures/Lisp/HashMaps.mac")$

det_cl(n) := block([N : setn(n), P, MS, c0, c0l, c1,c1l, s,sl, h, MSA, C],
 P : powerset(N),
 MS : powerset(P),
 c0 : lambda([S], setdifference(P,S)),
 c1 : lambda([S], ecomp(S,N)),
 s : lambda([S], subset_closure(S)),
 h : osm2hm(ll2osm(listify(MS),create_list(i,i,1,2^(2^n)))),
 MSA : l2ary(listify(MS)),
 c0l : create_list(ev_hm(h,c0(MSA[i])), i,1,2^(2^n)),
 c1l : create_list(ev_hm(h,c1(MSA[i])), i,1,2^(2^n)),
 sl : create_list(ev_hm(h,s(MSA[i])), i,1,2^(2^n)),
 C : closure_bydef_grd(trf_l_compo, {c0l,c1l,sl}),
 length(C)
)$
create_list(det_cl(n),n,0,3);
  [2,28,28,28]
   \endverbatim
   </li>
   <li> So it seems as soon as the base set contains at least one element,
   the closure contains exactly 28 elements. One now needs to determine
   them. </li>
   <li> The above transformations c0,c1,s in list-form are
   \verbatim
[3,4,1,2]
[1,4,3,2]
[1,2,3,3]
   \endverbatim
   </li>
   <li> In Gap:
   \verbatim
LoadPackage("monoid");
c0 := Transformation([3,4,1,2]);
c1 := Transformation([1,4,3,2]);
s := Transformation([1,2,3,3]);
C := Semigroup(c0,c1,s);
Size(C);
  28
Centre(C);
  [ Transformation( [ 1, 2, 3, 4 ] ) ]
Idempotents(C);
  [ Transformation( [ 1, 1, 3, 1 ] ), Transformation( [ 1, 1, 3, 3 ] ), Transformation( [ 1, 1, 3, 4 ] ),
    Transformation( [ 1, 2, 3, 1 ] ), Transformation( [ 1, 2, 3, 3 ] ), Transformation( [ 1, 2, 3, 4 ] ),
    Transformation( [ 1, 3, 3, 1 ] ), Transformation( [ 1, 3, 3, 3 ] ), Transformation( [ 1, 3, 3, 4 ] ) ]
   \endverbatim
   </li>
   <li> Finding a presentation:
    <ol>
     <li> First by using Gap directly:
     \verbatim
phi := IsomorphismFpMonoid(C);
recursion depth trap (5000)
  ??

FC := Range(phi);
GeneratorsOfFpMonoid(FC);
RelationsOfFpMonoid(FC);
     \endverbatim
     but unfortunately this seems to fail (on a 32-bit machine as well as on a
     64-bit machine): Perhaps a newer version of the Monoid-package exists? Or
     perhaps one needs more memory? </li>
     <li> Now "bottom-up", trying to guess a complete set of relations. </li>
     <li> Using three generators m[1] = c0, m[2] = c1, m[3] = s together with
     the four basic relations, expressing that c0,c1 are involutions which
     commute and that s is idempotent:
     \verbatim
f3 := FreeMonoid(3);
m := GeneratorsOfMonoid(f3);
r1 := [m[1]^2, m[1]^0];
r2 := [m[2]^2, m[2]^0];
r3 := [m[1]*m[2], m[2]*m[1]];
r4 := [m[3]*m[3], m[3]];
C0 := f3 / [r1,r2,r3,r4];
Size(C0);
  ??
     \endverbatim
     </li>
     <li> Using the transversal-operator Tr = c0 s c1 and
     closure under superset-formation s' = c1 s c1, adding
     the relation Tr^2 = s':
     \verbatim
r5 := [(m[2]*m[3]*m[1])^2, m[2]*m[3]*m[2]];
C1 := f3 / [r1,r2,r3,r4,r5];
Size(C1);
  ??
     \endverbatim
     (Note that Gap composes transformations from left to right.)
     </li>
    </ol>
   </li>
  </ul>


  \todo Hypergraph transformations II
  <ul>
   <li> Additionally, let m: MS -> MS be subsumption elimination: m(S) =
   {T in S : there is no T' in S with T < T'}. </li>
   <li>
   \verbatim
det2_cl(n) := block([N : setn(n), P, MS, c0, c0l, c1,c1l, s,sl, m,ml, h, MSA, C],
 P : powerset(N),
 MS : powerset(P),
 c0 : lambda([S], setdifference(P,S)),
 c1 : lambda([S], ecomp(S,N)),
 s : lambda([S], subset_closure(S)),
 m : lambda([S], min_elements(S)),
 h : osm2hm(ll2osm(listify(MS),create_list(i,i,1,2^(2^n)))),
 MSA : l2ary(listify(MS)),
 c0l : create_list(ev_hm(h,c0(MSA[i])), i,1,2^(2^n)),
 c1l : create_list(ev_hm(h,c1(MSA[i])), i,1,2^(2^n)),
 sl : create_list(ev_hm(h,s(MSA[i])), i,1,2^(2^n)),
 ml : create_list(ev_hm(h,m(MSA[i])), i,1,2^(2^n)),
print("c0l = ",c0l),
print("c1l = ",c1l),
print("sl = ", sl),
print("ml = ", ml),
 C : closure_bydef_grd(trf_l_compo, {c0l,c1l,sl,ml}),
 length(C)
)$
:lisp (ext:set-limit 'ext:heap-size 1073741824)
for i : 0 thru 3 do print(i, det2_cl(i));
0 2
1 176
2 404
3 
   \endverbatim
   </li>
   <li> In Gap:
    <ol>
     <li> n=1:
     \verbatim
c0 := Transformation([3,4,1,2]);
c1 := Transformation([1,4,3,2]);
s := Transformation([1,2,3,3]);
m := Transformation([1,2,2,4]);
M1 := Monoid(c0,c1,s,m);
Size(M1);
  176
     \endverbatim
     </li>
     <li> n=2:
     \verbatim
c0 := Transformation([5,12,15,16,1,14,13,10,11,8,9,2,7,6,3,4]);
c1 := Transformation([1,14,15,8,5,12,7,4,11,16,9,6,13,2,3,10]);
s := Transformation([1,2,3,5,5,6,5,5,9,3,5,5,6,5,5,9]);
m := Transformation([1,2,2,2,2,2,2,2,2,10,10,13,13,14,16,16]);
M2 := Monoid(c0,c1,s,m);
Size(M2);
  404;
     \endverbatim
     </li>
     <li> n=3:
     \verbatim
c0 := Transformation([9,136,199,230,245,252,255,256,1,254,253,250,251,248,249,242,247,246,243,244,237,240,241,226,239,
 238,235,236,233,234,227,232,231,228,229,214,221,224,225,194,223,222,219,220,217,218,211,216,215,
 212,213,206,209,210,195,208,207,204,205,202,203,196,201,200,197,198,167,182,189,192,193,130,191,
 190,187,188,185,186,179,184,183,180,181,174,177,178,163,176,175,172,173,170,171,164,169,168,165,
 166,151,158,161,162,131,160,159,156,157,154,155,148,153,152,149,150,143,146,147,132,145,144,141,
 142,139,140,133,138,137,134,135,72,103,118,125,128,129,2,127,126,123,124,121,122,115,120,119,116,
 117,110,113,114,99,112,111,108,109,106,107,100,105,104,101,102,87,94,97,98,67,96,95,92,93,90,91,
 84,89,88,85,86,79,82,83,68,81,80,77,78,75,76,69,74,73,70,71,40,55,62,65,66,3,64,63,60,61,58,59,52,
 57,56,53,54,47,50,51,36,49,48,45,46,43,44,37,42,41,38,39,24,31,34,35,4,33,32,29,30,27,28,21,26,25,
 22,23,16,19,20,5,18,17,14,15,12,13,6,11,10,7,8]);
c1 := Transformation([1,226,239,240,113,110,103,40,9,72,47,16,79,106,43,12,75,50,19,82,237,230,167,136,199,174,143,206,
 233,170,139,202,177,146,209,112,109,102,39,8,71,46,15,78,105,42,11,74,49,18,81,236,229,166,135,
 198,173,142,205,232,169,138,201,176,145,208,241,114,111,104,41,10,73,48,17,80,107,44,13,76,51,20,
 83,238,231,168,137,200,175,144,207,234,171,140,203,178,147,210,99,108,101,38,7,70,45,14,77,100,37,
 6,69,36,5,68,235,228,165,134,197,172,141,204,227,164,133,196,163,132,195,254,255,128,125,118,55,
 24,87,62,31,94,121,58,27,90,65,34,97,252,245,182,151,214,189,158,221,248,185,154,217,192,161,224,
 127,124,117,54,23,86,61,30,93,120,57,26,89,64,33,96,251,244,181,150,213,188,157,220,247,184,153,
 216,191,160,223,256,129,126,119,56,25,88,63,32,95,122,59,28,91,66,35,98,253,246,183,152,215,190,
 159,222,249,186,155,218,193,162,225,2,123,116,53,22,85,60,29,92,115,52,21,84,3,4,67,250,243,180,
 149,212,187,156,219,242,179,148,211,130,131,194]);
s := Transformation([1,2,3,29,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,25,25,24,24,25,24,24,25,29,31,31,32,31,31,32,9,9,9,9,9,9,
 9,9,9,9,9,9,9,9,9,9,59,56,55,55,56,55,55,59,60,62,62,63,62,62,66,29,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
 9,25,25,24,24,25,24,24,25,29,31,31,32,31,31,32,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,59,56,55,55,56,55,
 55,59,123,125,125,126,125,125,129,3,29,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,25,25,24,24,25,24,24,25,29,
 31,31,32,31,31,32,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,59,56,55,55,56,55,55,59,60,62,62,63,62,62,66,29,
 9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,25,25,24,24,25,24,24,25,29,31,31,32,31,31,32,9,9,9,9,9,9,9,9,9,9,
 9,9,9,9,9,9,59,56,55,55,56,55,55,59,123,125,125,126,125,125,129]);
m := Transformation([1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,130,130,130,130,187,187,190,190,191,
 193,193,187,187,190,190,191,193,193,130,187,187,190,190,191,193,193,187,187,190,190,191,193,193,
 130,130,187,187,190,190,191,193,193,187,187,190,190,191,193,193,130,187,187,190,190,191,193,193,
 187,187,190,190,191,193,193,194,194,211,243,243,253,253,216,225,225,250,250,253,253,223,225,225,
 211,243,243,253,253,216,225,225,250,250,253,253,223,225,225,226,242,243,243,253,253,247,256,256,
 250,250,253,253,254,256,256,242,243,243,253,253,247,256,256,250,250,253,253,254,256,256]);
M3 := Monoid(c0,c1,s,m);
Size(M3);
  656;
     \endverbatim
     One sees that the Gap-algorithm is vastly more efficient than our approach
     by definition (of course). </li>
     </li>
     <li> n=4: Now we need to compute the four transformations directly
     in Gap (instead of copy-and-paste them from Maxima, as above). Of course,
     we have now 2^16=65536 elements in the base-set, but one needs to try
     it (in order to see whether perhaps some stationary point is reached).
     </li>
    </ol>
   </li>
  </ul>

*/

