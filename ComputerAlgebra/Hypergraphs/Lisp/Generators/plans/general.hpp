// Oliver Kullmann, 19.7.2008 (Swansea)
/* Copyright 2008, 2009, 2010 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file ComputerAlgebra/Hypergraphs/Lisp/Generators/plans/general.hpp
  \brief Plans regarding generators for hypergraphs


  \bug ramseyrv_ohg handles r=0 incorrectly
  <ul>
   <li> ramseyrv_ohg(0,0,0) should return [[rv()],[{rv()}]], not 
   [[rv()],[{{}}]]. </li>
  </ul>


  \todo Connections
  <ul>
   <li> Finally all the generators provided here are also to be provided at
   C++ level in module Combinatorics/Hypergraphs/Generators; see
   Combinatorics/Hypergraphs/Generators/plans/general.hpp. </li>
  </ul>


  \todo Organisation
  <ul>
   <li> The current Generators/Generators.mac needs to be split into several
   files:
    <ol>
     <li> Basics.mac </li>
     <li> VanderWaerden.mac </li>
     <li> GreenTao.mac : DONE </li>
     <li> Schur.mac </li>
     <li> Rado.mac DONE </li>
     <li> Folkman.mac </li>
     <li> Hindman.mac DONE </li>
     <li> Ramsey.mac </li>
    </ol>
   </li>
  </ul>
  
  
  \todo Statistics
  <ul>
   <li> For all generated hypergraphs we need accompanying
   statistic-functions. </li>
   <li> As for clause-set statistics. </li>
  </ul>


  \todo Hypergraphs of arithmetic progressions
  <ul>
   <li> The current implementation of arithprog_ohg/arithprog_hg can only
   handle small values of n --- otherwise we get a stack-size error!
   \verbatim
C-STACK overflow at size 139456. Stack can probably be resized.
   \endverbatim
   (this on a 32-bit machine with 2GB memory). </li>
   <li> Perhaps this is due to Ecl --- can we grow the stack size?!
    <ol>
     <li> ulimit reports that there are no restrictions from the bash-side.
     </li>
     <li> There are various Ecl memory limits which are discussed in the
     manual -
     http://ecls.sourceforge.net/new-manual/re34.html#table.memory.limits . 
     </li>
     <li> In this case the C-STACK is overflowing with a current limit of 
     128KB. This can be adjusted to say 1MB in the following way:
     \verbatim
:lisp (ext:set-limit 'ext:c-stack 1048576)
     \endverbatim
     </li>
     <li> MG: Please make the documentation of Ecl
     available (locally), document all the memory option (apparently
     there are five: "frame-stack, binding-stack, c-stack, heap-size,
     lisp-stack"; they can also be set on the command line), together
     with appropriate values, and move this important documentation into its 
     right (general) place. Likely the OKlibrary should provide meta-commands,
     which work for all Lisps supported; perhaps just asking for
     one argument, the amount of memory available for Maxima,
     and then calculating the approriate values.
     One also needs to find out how to pass command-line arguments to
     ecl (for example "--frame-stack 4096"). </li>
     <li> Compare "Reasonable memory and stack limits" in
     Buildsystem/MasterScript/SpecialProcessing/plans/Maxima_Init.hpp. </li>
    </ol>
   </li>
   <li> On the other hand, a non-recursive solution is also very easy to
   produce. </li>
   <li> However, such little problems shouldn't pose a problem! </li>
  </ul>


  \todo Sudoku
  <ul>
   <li> Create Sudoku-hypergraphs (such that the Sudoku-problems can be
   expressed as strong colouring problems). </li>
   <li> For box dimension p the vertex set should be {1,...,p}^2. </li>
   <li> The 3N hyperedges (N=p^2) just correspond to the rows, columns
   and boxes (the hypergraph is thus N-uniform). </li>
  </ul>


  \todo %Ramsey hypergraphs
  <ul>
   <li> We should always have that standardisation should not change the
   order of vertices or hyperedges, however this seems to be the case here?
   </li>
   <li> Perhaps we should use complete_hg and variations. </li>
   <li> Compare with ComputerAlgebra/Hypergraphs/Lisp/Generators/GreenTao.mac
   (so that we arrive at a certain standardisation of generator-facilities).
   </li>
   <li> One needs to revise the extreme cases; compare "Ramsey problems"
   in ComputerAlgebra/Satisfiability/Lisp/Generators/RamseyTheory/plans/RamseyProblems.hpp.
   </li>
   <li> Providing a standardised vertex set:
    <ol>
     <li> DONE
     We only need to consider lexicographical ordering of the
     vertex names. Actually, in order to preserve monotonicity, we better
     use colexicographical ordering. </li>
     <li> This standardised hypergraph has then a canonical order-preserving
     isomorphism to ramsey_ohg(q,r,n).
      <ol>
       <li> For this to hold (for the vertices) we needed ramsey_ohg
       to use colexicographical ordering. </li>
       <li> Perhaps this is a sensible thing to do; however it seems
       we don't need to do something on the hyperedges (i.e., we continue
       to use lexicographical order there). </li>
       <li> Currently we use the lexicographical order of ramsey_ohg on
       vertex set and hyperedge set, but using colexicographical ranking. </li>
       <li> This has the advantage that ramsey_ohg is easy to compute and
       isomorphic to ramsey_stdohg. </li>
       <li> But for n' >= n we don't have that ramsey_stdohg(q,r,n') is
       an extension of ramsey_stdohg(q,r,n) --- we only have that
       ramsey_stdhg(q,r,n) is a subhypergraph of ramsey_stdhg(q,r,n'). </li>
      </ol>
     </li>
     <li> The same numbering should also be used in the C++ generator
     (see Ramsey.cpp). </li>
     <li> So that we can easily create additional clauses with Maxima,
     added then to the C++-generated files. </li>
    </ol>
   </li>
   <li> Accompanying statistics are needed.
    <ol>
     <li> See okltest_ramsey_hg for the formula for the number of
     hyperedges. </li>
     <li> Likely only basic statistics should be computed, while for example
     the size of the automorphism group etc. is handled in module.
     RamseyTheory/Lisp/Ramsey. </li>
    </ol>
   </li>
  </ul>


  \todo Generalised %Ramsey hypergraphs
  <ul>
   <li> We can define %Ramsey hypergraphs for arbitrary hypergraphs G
   (ramsey_hg uses the complete r-graph).
    <ol>
     <li> The vertices are the hyperedges of G. </li>
     <li> Hyperedges are sets of hyperedges of G which are the hyperedge-set
     of a complete q-graph. </li>
     <li> If G is a graph, then we are considering the hypergraph of
     "cliques", restricted to cliques of size q, and where the clique
     is viewed as a collection of edges. </li>
     <li> We need to check whether this is the common point of view. </li>
    </ol>
   </li>
  </ul>

*/

