// Oliver Kullmann, 30.11.2007 (Swansea)
/* Copyright 2007 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file ComputerAlgebra/Satisfiability/Lisp/ClauseSets/plans/general.hpp
  \brief Plans for Maxima-components regarding clause-sets


  \todo Create milestones


  \todo Write tests


  \todo Write docus


  \todo Input and output
  <ul>
   <li> Functions currently in
   ComputerAlgebra/Satisfiability/Lisp/ClauseSets/BasicOperations.mac
   should move to their own file "InputOutput.mac". </li>
   <li> The usage of "print" likely should be replaced by "printf" from
   package "stringproc". </li>
   <li> We need also reading from Dimacs-files. </li>
  </ul>


  \todo Random generator
  <ul>
   <li> Using the maxima-aes-implementation, implement the random generator
   as in Experimentation/RandomGenerator/plans/general.hpp. </li>
  </ul>


  \todo Resolution
  <ul>
   <li> Perhaps this topic should go into its own plans-file. </li>
   <li> min_resolution_closure_cs :
    <ol>
     <li> As in "Maxima"-"Monitoring" in ComputerAlgebra/plans/general.hpp,
     perhaps the monitoring-output should be standardised, containing the name
     of the function? </li>
     <li> A second output is needed, with the list of c(F_i)
     for the successive stages. DONE </li>
     <li> In monitoring mode these numbers are output once a round is
     completed (compare "Maxima"-"Monitoring" in
     ComputerAlgebra/plans/general.hpp). DONE </li>
    </ol>
   </li>
   <li> resolution_closure_cs
    <ol>
     <li> Same regarding monitoring as min_resolution_closure_cs. </li>
     <li> The implementation is very similar to min_resolution_closure_cs:
     Should we construct a common generalisation? </li>
    </ol>
   </li>
   <li> DP
    <ol>
     <li> We need also the greedy heuristics, which chooses the DP-variable
     such that the number of clauses for the next level is minimised. </li>
    </ol>
   </li>
   <li> Resolution proofs
    <ol>
     <li> The natural format for a resolution proof is a non-empty list,
     where each entry is either a clause (an "axiom") or a pair consisting
     of a clause (the "resolvent") and a pair of (smaller) indices (the
     indices of the "parent clauses"). </li>
     <li> We need a correctness-checker. </li>
     <li> We should also investigate the existing file-formats for resolution
     proofs, and we should provide input- and output-facilities. </li>
     <li> This linear format is in 1-1 correspondence to the representation
     via labelled dag's; we need a representation of labelled graphs,
     digraphs and labelled digraphs. </li>
     <li> The above can easily be generalised to non-boolean clause-sets.
     </li>
    </ol>
   </li>
   <li> Bounded resolution
    <ol>
     <li> Implement the different forms of bounded resolution. </li>
     <li> In this way we can determine the width of a clause-set. </li>
    </ol>
   </li>
   <li> Read-once resolution proofs
    <ol>
     <li> Write a checker whether a resolution proof is read-once. </li>
     <li> Implement the translation of "has read-once refutation" into
     SAT. </li>
    </ol>
   </li>
  </ul>


*/

