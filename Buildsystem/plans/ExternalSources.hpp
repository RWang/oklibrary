// Oliver Kullmann, 28.2.2006 (Swansea)

/*!
  \file Buildsystem/plans/ExternalSources.hpp
  \brief Plans for the makefile responsible for handling external sources

  \bug Building gcc_doc

  <ul>
   <li> Does not work (that is, the link at
   system_directories/doc/index.html is not working),
   since apparently the man-pages need to be build. </li>
   <li> *Only* the documentation is to be extracted, not the whole
   distribution. </li>
  </ul>

  \bug Building-Boost Errors
  
  <ul>
   <li>
   Suddenly building boost on cs-wsok with a local gcc (version 3.4.3 or
   3.4.6 for example) doesn't work anymore, but there are linking errors.
   It seems that on csltok everything works, so that it could be a
   64bit thing.
  
   What did change?? And it seems that gcc versions for example 4.1.1
   do work?? Since versions below 4.0.0 don't work, while above work,
   it seems that the system-gcc (4.0.2) interferes; perhaps it tries to
   link with the 32bit-version, can't do that, and then falls back to the
   system version?
  
   What is the role of LD_LIBRARY_PATH ?? (On cs-wsok it is empty.)
  
   OK (12.1.2007): When building boost with gcc-version 3.4.3 or 3.4.6, we get
  
   ...failed updating 10 targets...
   ...skipped 14 targets...
  
   Why this?
  
   We should check in general whether building boost links to the 32bit
   or to the 64bit version.
   </li>
  </ul>
  
  \todo Building Ubcsat (OK, ML):
  - What is the meaning of "tag" and "tag_" ??? The names should tell.
  - No file modification in the external sources. DONE

  \todo Documenting ExternalSources.mak
  <ul>
   <li> The old OKBuildsystem/ExternalSources/doc.mak is gone?
   So documentation building should happen automatically (when building
   the package). </li>
   <li> Document packages:
    <ul>
     <li> Mhash (remark about corrected files; content of package) </li>
     <li> Postgresql </li>
     <li> UBCSAT : DONE </li>
    </ul>
   </li>
   <li> Move the documentation from ExternalSources.mak to
   Buildsystem/docus/ExternalSources.hpp. DONE </li>
  </ul>

  \todo Building documentation:
   - Documentation building should be done automatically when building.
   - We should extract only the documentation from the archives (and
   remove everything else which is not needed).
   
  \todo Mhash
  <ul>
   <li> Make a bug report about version 0.9.9 of Mhash (
   see the two files in Kryptologie/Mhash/corrected/mutils --- two
   commas too much). </li>
   <li> We need some user-information for mhash (how to use the installed
   files). </li>
   <li> It seems yet only a local build is available? As discussed above, then
   also the option for a global installation should be available. </li>
   <li> The build-instructions for mhash should be as similar as possible
   to those for Boost. </li>
   <li> Shouldn't the default for building mhash be using the recommended
   local gcc-version? </li>
   <li> It seems that cleanmhash should also remove the installation directory.
   (MH) Isn't it the case that we want cleanmhash only to remove the build
   directory - so that the local installation can still be used after cleaning?
   Then to clean everything there is already the target "cleanallmhash". </li>
  </ul>
   
  \todo General
  - It would ge good, if after doing a local installation, easily the installation could also be
  make global.
  - Optionally there should be also local versions of valgrind and doxygen (and other tools).
  This is necessary on systems where the user does not have root access.
  
  \todo Gcc
  <ul>
   <li> Instead of, e.g., "make gcc-4.1.2", wouldn't it be more consistent with
   building Boost to use instead "make gcc gcc-version=4.1.2" ? </li>
   <li> If variable "gcc-version" is set, then it should have one of the
   allowed values (while otherwise we get an error). </li>
   <li> We must understand, how gcc interacts with 32- and 64-bit
   environments, and how to take control of this. </li>
   <li> There should be make-variables, which allow control over
   some settings for the build of gcc. </li>
  </ul>
  
  \todo Boost
  <ul>
   <li> It should be possible to say "gcc-version=recommended". </li>
   <li> Instead of "boost boost_recommended=1_33" we should use
   "boost boost-version=1_33". </li>
   <li> The default for generic.mak is to use the recommended local
   gcc-installation --- shouldn't this then be also for building boost
   the default ? </li>
   <li> Installation of bjam should be improved: Having exactly one
   bjam-installation for each boost-version, and no need to recreate
   it if it's already there. Or, perhaps better: We just leave it in
   the distribution directory? </li>
   <li> Building boost should include copying the documentation to doc
   (in the subdirectory boost-1_33_1 for example). </li>
   <li> In the long run, it seems that actually supporting different versions
   of Boost is not feasible (the library will likely always use the newest
   version), so finally supporting different Boost version should be dropped
   (but the general machinery is worth keeping)?!? </li>
  </ul>

  \todo PostgreSQL
  - Update PostgreSQL to version 8.1 (or later; and test it).
  - "make initialise-database" should work with the recommended version (and no specification
  of the pgsql-version should be needed).
  - A detailed user-manual is needed (on how to use the installed database).
  
  \todo Other sources:
  - Build a local version of Xerces.
  - Build a local version of gmp.
  - Build the R system (locally and globally).
  - Build and incorporate graphviz (the dot-tool is needed by doxygen for creating the graphs)
  and tulip.
  - SOCI (soci.sourceforge.net) ?
  - gcc-xml (www.gccxml.org) ?
  
  \todo Tools
  - Investigate the NiX system (a system for managing libraries).
  - Investigate the Poco C++ library (http://www.pocoproject.org; see
    also [C Vu, 19:2, pages 12-15]).
     
*/
