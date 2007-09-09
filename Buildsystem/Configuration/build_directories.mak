# Oliver Kullmann, 14.7.2007 (Swansea)

# Here the directories and files specific for OKlib-building are specified

# Top-level directory for all executables:
bin_dir ?= $(system_directories)/bin

# Top-level directory for all object-files:
lib_dir ?= $(system_directories)/lib

# Top-level directory for all documentation:
doc_dir ?= $(system_directories)/doc

# Top-level directory for all dependency files,
# error, message and log files, and latex auxilliary files:
aux_dir ?= $(system_directories)/aux

# Directory for all latex auxilliary files:
latex_dir ?= $(aux_dir)/latex

# Directory for all dvi files:
dvi_dir ?= $(doc_dir)/dvi

# Directory for all dependency files:
dependencies_dir ?= $(aux_dir)/dependencies

# Directory for all test executables:
test-bin_dir ?= $(bin_dir)/tests

# Directory for current module test object-files:
test-lib_dir ?= $(lib_dir)/tests/$(module-name)

# Directory for current module test dependency files:
test-aux_dir ?= $(aux_dir)/tests/$(module-name)

# Directory for log-files:
log_dir ?= $(system_directories)/log

# Html directories:
local_html_dir ?= $(doc_dir)/local_html
internet_html_dir ?= $(doc_dir)/internet_html
documents_html_dir ?= $(doc_dir)/documents

build_directories = \
               $(bin_dir) \
               $(lib_dir) \
               $(aux_dir) \
               $(latex_dir) \
               $(dependencies_dir) \
               $(doc_dir) \
               $(doxygen_html_dir) \
               $(test-bin_dir) \
               $(test-lib_dir) \
               $(test-aux_dir) \
               $(local_html_dir) \
               $(internet_html_dir) \
               $(log_dir)

OKsystem_include := -I$(OKsystem)

oklib_building_log ?= $(log_dir)/OKlibBuilding
external_sources_log ?= $(log_dir)/ExternalSources

documents_dir ?= $(OKsystem)/documents

oklibrary_dvi_documents ?= FullDocumentation
OKlibrary_full_documentation_dvi_location ?= $(documents_html_dir)/FullDocumentation.dvi

