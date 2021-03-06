// Matthew Gwynne, 27.3.2009 (Swansea)
/* Copyright 2009 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file Investigations/Cryptography/AdvancedEncryptionStandard/plans/general.hpp
  \brief On investigations into the Advanced Encryption Standard


  \todo Improve formulations: MG (as soon as possible!)
  <ul>
   <li> The general naming conventions must be followed:
    <ol>
     <li> DONE No camel-cases here (like "removeTopNVars", "AESHexToPA", 
     "NewCL", "mergeSameVarCNFs". </li>
     <li> Grammatical case indicates verb or noun! </li>
    </ol>
   </li>
   <li> DONE Clean-up minisat output (of course, no intermediate results).
   <ul>
    <li> What is meant by intermediate results here? </li>
    <li> Solver output should be concise, and individual restarts of solvers
    such as minisat should not be included in plans/docus unless there is 
    specifically something interesting to present. </li>
   </ul>
   </li>
   <li> (DONE see for example "Generating experiments" in 
   Experimentation/Investigations/Cryptography/AdvancedEncryptionStandard/plans/BreakingAES.hpp)
   Explanations needed! Experiments need full specifications (to be
   reproducible). </li>
   <li> DONE More care! (Of course, the doxygen-output needs to be inspected) 
   </li>
   <li> (DONE see "Experiments") And discussions! What are the underlying 
   problems to be investigated?
   </li>
   <li> DONE No names consisting only of upper-case letters! See
   "Weak state of the whole module" in
   Experimentation/Investigations/Cryptography/plans/general.hpp. </li>
   <li> DONE No "is useful". </li>
   <li> DONE No "may be used". </li>
  </ul>


  \todo Connections
  <ul>
   <li> See
   ComputerAlgebra/Cryptology/Lisp/CryptoSystems/Rijndael/plans/general.hpp
   for an AES implementation in Maxima. </li>
   <li> See
   ComputerAlgebra/Cryptology/Lisp/Cryptanalysis/Rijndael/plans/general.hpp
   for an AES translation into SAT. </li>
  </ul>


  \todo Experiments
  <ul>
   <li> The following are the main areas requiring experiments:
    <ul>
     <li> Breaking AES for reduced round variants. </li>
     <li> Investigations into different representations of
     the Sbox. </li>
     <li> Investigations into replacing the Sbox with random permutations.
     </li>
     <li> Investigations into replacing the multiplication with constant field
     elements with random permutations. </li>
     <li> Investigations into encryption and decryption using different AES 
     representation. </li>
     <li> Investigations into small-scale variations of the AES (see 
     "Generalisations" in 
     ComputerAlgebra/Cryptology/Lisp/CryptoSystems/Rijndael/plans/general.hpp).
     </li>
    </ul>
   </li>
   <li> See 
   Investigations/Cryptography/AdvancedEncryptionStandard/plans/BreakingAES.hpp
   for 
   experiments regarding breaking AES. </li>
   <li> See 
   Investigations/Cryptography/AdvancedEncryptionStandard/plans/SboxInvestigations.hpp
   for experiments regarding the Sbox, it's representations and possible 
   replacements. </li>
   <li> See 
   Investigations/Cryptography/AdvancedEncryptionStandard/plans/FieldMulInvestigations.hpp 
   for experiments regarding multiplication by constants in GF(2^8),
   their representations, and possible replacements. </li>
   <li> See 
   Investigations/Cryptography/AdvancedEncryptionStandard/plans/EncryptionDecryption.hpp 
   for experiments regarding computing encryption and decryption using the AES 
   SAT translation. </li>
   <li> Solvers to be used: 
    <ul>
     <li> OKsolver_2002 </li>
     <li> minisat2 </li>
     <li> ubcsat (1-0-0) </li>
     <li> picosat913 </li>
     <li> Satz215 </li>
     <li> sp </li>
     <li> march_pl </li>
    </ul>
   </li>
  </ul>


  \todo Investigating conditions and their representations
  <ul>
   <li> A first central research question is how to choose appropriate
   representations of the conditions which altogether specify AES. </li>
   <li> More specifically, clause-sets representing the S-box and the
   various multiplications (with constants) are to be investigated upon
   their influence on SAT solving. </li>
   <li> See ComputerAlgebra/Satisfiability/Lisp/Preprocessing/plans/general.hpp
   for the general perspective, where one starts from a CNF and derives
   DNFs from it by partitioning, while we have already given the DNFs (but
   not some original CNF). </li>
   <li> Studying the representations of the Sbox
    <ol>
     <li> See
     ComputerAlgebra/Cryptology/Lisp/Cryptanalysis/Rijndael/plans/SboxAnalysis.hpp.
     </li>
     <li> That module is not properly maintained: Actions for MG. </li>
     <li> See "r-based representations" in 
     Experimentation/Investigations/BooleanFunctions/plans/ReductionBasedRepresentations.hpp . </li>
     <li> A 0-based CNF-representation without additional variables is likely
     infeasible to use. </li>
     <li> What about the Tseitin-translation of the Sbox-DNF? 
      <ol>
       <li> Could it be 0-based? Since the DNF-representation is hitting, it
       is 0-based. </li>
       <li> MG: Is it not 1-based but not 0-based, as every clause has at least
       one of the new variables in it and therefore applying a full falsifying
       assignment, will not yield the empty clause. The empty clause will only
       occur after unit clause propagation. </li>
       <li> MG: Isn't the only 0-based clause-set representation, precisely the
       prime implicates? </li>
       <li> Is there a simple example of a clause-set which is 2-based but not
       1-based? </li>
       <li> Most natural should be to use dualts_fcl in
       ComputerAlgebra/Satisfiability/Lisp/ClauseSets/Constructions.mac. </li>
      </ol>
     </li>
     <li> It seems most promising (for now) to consider here r=r_1 and r=r_2,
     applied to the sets of prime implicates of the various "boxes" involved.
     </li>
     <li> Perhaps actually the hitting-CNFs representing the Sbox might have
     values, since we have special algorithms. So other reductions than just
     the r_k-reductions are useful to consider in general. </li>
    </ol>
   </li>
  </ul>


  \todo Cryptographic properties of AES
  <ul>
   <li> Given a correct translation of the AES into a SAT problem, represented
   by the predicate "AES(P,K,C)" where P, K, and C are lists of 128 variables,
   several questions regarding certain cryptographic properties of the AES can
   be formulated as SAT problems. </li>
   <li> Does AES have two distinct keys which map the same plaintext blocks 
   to the same ciphertext block?
   <ul>
    <li> This can be translated as "AES(P,K1,C) and AES(P,K2,C) and 
    NEQ(K1,K2)" where "NEQ" specifies that K1 differs form K2 in at least one 
    bit. </li>
   </ul>
   </li>
   <li> Does AES have any key which acts as the identity on one or plaintext
   blocks?
   <ul>
    <li> This can be translated as "AES(P,K,P)". </li>
    <li> This can also be expanded trivially to find keys where AES algorithm
    acts as the identity on "k" or more plaintext blocks (for reasonable k) 
    by simply considering "AES(P1,K,P1) and AES(P2,K,P2) and ... and 
    AES(Pk,K,Pk) and NEQ(P1,P2,...,Pk)" where here "NEQ" specifies that every 
    argument differs in at least one variable from every other. </li>
    <li> This may also be made more damaging to the AES by considering 
    specifically plaintexts of a particular form (plaintext blocks
    representing particular common ASCII sequences). </li>
   </ul>
   <li> Does AES have any key which is the inverse of any other for some 
   plaintext/ciphertext pair?
   <ul>
    <li> Considering only a single piece of plaintext (that there are two
    keys K1 and K2 for which AES with that K1 maps some plaintext P to 
    ciphertext C and AES with K2 maps C to P) can be translated simply as 
    "AES(P,K1,C) and AES(C,K2,P)". </li>
    <li> This can be expanded to find keys K1 and K2 where AES using K2 is
    the inverse of AES with K1 for at least "k" plaintext blocks in the 
    following way: "AES(P1,K1,C1) and AES(C1,K2,P1) and ... and 
    AES(Pk,K(k-1),Ck) and AES(Ck,Kk,Pk) and NEQ(P1,P2,...,Pk)" . </li>
    <li> There is obviously then the question of whether there is key which 
    acts as it's own inverse for at least "k" plaintext blocks, where
    K1=K2 etc. </li>
   </ul>
   </li>
  </ul>


  \todo General organisation
  <ul>
   <li> All the experiments must be fully reproducible. Thus *only* tools
   as provided by the OKlibrary are to be used, *NO* private code or private
   schemes in any form. </li>
   <li> Besides reproducibility, the point is to strengthen the OKlibrary,
   by continuous improvement, not to weaken it by hiding. </li>
   <li> DONE Directory structure:
    <ol>
     <li> DONE
     The main topic here is not investigation of certain solvers, but to
     investigate the interaction of cryptography and (generalised) SAT
     solving. </li>
     <li> DONE Thus solver-names as file-names should only occur, if at all, in
     sub-directories associated with specific investigations. </li>
     <li> The general standards for naming in the OKlibrary have to be
     observed:
      <ul>
       <li> DONE Non-generic filenames start always with a capital letter.
       </li>
       <li> No file- (or directory-)name consists only of capital letters.
       </li>
      </ul>
     </li>
    </ol>
   </li>
  </ul>


  \todo DONE More experiments
  <ul>
   <li> DONE What is the meaning of
   "Experiments on AES with the first 32 key bits not set" ? And what does
   the "summary" show? Apparently only trivial results, which are likely of
   no interest. 
   <ul>
    <li> This was regarding initial investigations where all plaintext and 
    ciphertext variables were set to relevant values and the last 96 key 
    variables were set. </li>
    <li> 32 bits were chosen as the AES translation to CNF, using the small CNF
    representations, presented a challenge to solvers for even very small 
    numbers of key bits left "unknown"/"unset" in the SAT problem. </li>
    <li> The experiments were over rounds 2,4,6,8, and 10. </li>
    <li> Experimental data and results has now been moved. See "Experiments". 
    </li>
   </ul>
   </li>
   <li> DONE For the trivial instances (message and key set) more solvers need
   to be considered. In its own file. </li>
   <li> DONE Also ciphertext and key set are to be investigated. </li>
   <li> (MOVED to Experiments) 
   Important is that we systematically study variations of AES:
    <ol>
     <li> the different sizes as belonging to Rijndael </li>
     <li> small-scale variations </li>
     <li> replacing the Sbox by other permutations (random ones, or
     very simple ones) </li>
     <li> replacing the multiplications with certain constants by other
     permutations </li>
     <li> replacing the row- and column-permutations by other permutations.
     </li>
    </ol>
   </li>
   <li> DONE Plan for more experiments! </li>
  </ul>

*/
