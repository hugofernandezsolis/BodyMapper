file(REMOVE_RECURSE
  "libIPC.a"
  "libIPC.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/IPC.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
