// Oliver Kullmann, 21.7.2007 (Swansea)

/*!
  \file ComputerAlgebra/Satisfiability/TauMachinery/plans/general.hpp
  \brief Plans regarding the tau function (see SAT-handbook article of OK)
  
  
  \todo Tau for Maxima
  <ul>
   <li> Defining tau using the precise but slow interval-halving:
    <ol>
     <li> How to define examples for functions? </li>
     <li> And it should be possible to define a variation which doesn't
     take a list but a variable number of arguments (for the tuple-values). DONE (define the
     n-ary function taun, and for plotting the fixed 2-ary resp. 3-ary function tau2, tau3) </li>
     <li> One has to do something here in case lower and upper bound are already very
     close. DONE (using the sign-check) </li>
     <li> Perhaps one should define chi(t) as a function x -> apply("+", x^(-t)). DONE </li>
    </ol>
   </li>
   <li> Using the faster Newton-method:
   \verbatim
load (descriptive)$ 
load (newton1)$
taunt(t,eps) := newton(apply("+", x^(-t))-1, x, length(t)^(1/mean(t)), eps);
   \endverbatim
    <ol>
     <li> Again, one should define a variant without lists (but variadic). </li>
     <li> Are there reasonable default values for eps? </li>
     <li> Can a higher precision be used? Apparently not. </li>
     <li> If all arguments are integers, then actually an expression is returned.
     So well. </li>
     <li> Does the newton-procedure know how to differentiate the expression?
     Don't think so, but apparently one can't tell the newton-procedure
     about it? </li>
    </ol>
   </li>
   <li> How to make these definitions available? DONE (it seems that explicit load-instructions have
   to be issued for each Maxima-session) </li>
  </ul>


  \todo Reimplement the remaining functionality from Mupad/tau.mup in Maxima

*/

