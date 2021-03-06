// Matthew Gwynne, 12.8.2010 (Swansea)
/* Copyright 2010 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file Structures/Sets/SetAlgorithms/SubsumptionHypergraph.hpp
  \brief Tests for the components from SubsumptionHypergraph.hpp

*/

#ifndef TESTSUBSUMPTIONHYPERGRAPH_aaJNraVt3
#define TESTSUBSUMPTIONHYPERGRAPH_aaJNraVt3

#include <sstream>
#include <set>

#include <boost/assign/list_of.hpp>

#include <OKlib/Programming/Messages/Utilities/TrivialMessage.hpp>
#include <OKlib/Programming/Messages/messages/Levels.hpp>

#include <OKlib/TestSystem/TestBaseClass_DesignStudy.hpp>
#include <OKlib/TestSystem/TestExceptions_DesignStudy.hpp>
#include <OKlib/Structures/Sets/SetAlgorithms/SubsumptionHypergraph.hpp>

namespace OKlib {
  namespace SetAlgorithms {
    namespace tests {

# define OKLIB_FILE_ID new ::OKlib::Messages::Utilities::FileIdentification \
      (__FILE__, __DATE__, __TIME__, "$Date: 2010/08/12 12:08:08 $", "$Revision: 0.8 $")

      /*!
        \class Subsumption_hypergraph
        \brief Testing the subsumption hypergraph generator
      */

      template
        <template <class RangeF,
                   class RangeG,
                   class OutputContainerSets = std::list<std::list<std::list<int> > > >
         class Subsumption_hypergraph>
      OKLIB_TEST_CLASS(Test_Subsumption_hypergraph) {
        OKLIB_TEST_CLASS_C(Test_Subsumption_hypergraph) {}
      private :
        void test(::OKlib::TestSystem::Basic) {
          typedef int value_type;
          typedef std::set<std::set<value_type> > hypergraph_F_type;
          typedef std::set<std::set<value_type> > hypergraph_G_type;
          typedef std::list<std::list<std::set<int> > > hypergraph_output_type;
          typedef Subsumption_hypergraph<hypergraph_F_type, hypergraph_G_type, hypergraph_output_type > hypergraph_type;
          hypergraph_type sub_hyp;
          
          { // empty sequence
            hypergraph_F_type empty_F;
            hypergraph_output_type empty_output;
            empty_output = sub_hyp.subsumption_hypergraph(empty_F, empty_F);
            OKLIB_TEST_EQUAL_RANGES(empty_output, hypergraph_output_type());
            empty_output = sub_hyp(empty_F, empty_F);
            OKLIB_TEST_EQUAL_RANGES(empty_output, hypergraph_output_type());
          }
          { // example sequence
            hypergraph_G_type hg_F = boost::assign::list_of
              (boost::assign::list_of(1)(2)(3))
              (boost::assign::list_of(1)(2)(4))
              (boost::assign::list_of(1)(3)(5));
            hypergraph_F_type hg_G = boost::assign::list_of(boost::assign::list_of(1)(2)(3)(4));
            hypergraph_output_type intended_output = boost::assign::list_of(boost::assign::list_of
                                                                            (boost::assign::list_of(1)(2)(3))
                                                                            (boost::assign::list_of(1)(2)(4)));
            hypergraph_output_type example_output;
            example_output = sub_hyp.subsumption_hypergraph(hg_F, hg_G);
            OKLIB_TEST_EQUAL_W3(example_output, intended_output);
          }
        }
      };
    }
  }
}

# undef OKLIB_FILE_ID
#endif
