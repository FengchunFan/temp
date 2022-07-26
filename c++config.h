// Predefined symbols and macros -*- C++ -*-
00002 
00003 // Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005,
00004 // 2006, 2007, 2008, 2009, 2010, 2011 Free Software Foundation, Inc.
00005 //
00006 // This file is part of the GNU ISO C++ Library.  This library is free
00007 // software; you can redistribute it and/or modify it under the
00008 // terms of the GNU General Public License as published by the
00009 // Free Software Foundation; either version 3, or (at your option)
00010 // any later version.
00011 
00012 // This library is distributed in the hope that it will be useful,
00013 // but WITHOUT ANY WARRANTY; without even the implied warranty of
00014 // MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
00015 // GNU General Public License for more details.
00016 
00017 // Under Section 7 of GPL version 3, you are granted additional
00018 // permissions described in the GCC Runtime Library Exception, version
00019 // 3.1, as published by the Free Software Foundation.
00020 
00021 // You should have received a copy of the GNU General Public License and
00022 // a copy of the GCC Runtime Library Exception along with this program;
00023 // see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
00024 // <http://www.gnu.org/licenses/>.
00025 
00026 /** @file bits/c++config.h
00027  *  This is an internal header file, included by other library headers.
00028  *  Do not attempt to use it directly. @headername{iosfwd}
00029  */
00030 
00031 #ifndef _GLIBCXX_CXX_CONFIG_H
00032 #define _GLIBCXX_CXX_CONFIG_H 1
00033 
00034 // The current version of the C++ library in compressed ISO date format.
00035 #define __GLIBCXX__ 20111101
00036 
00037 // Macros for various attributes.
00038 //   _GLIBCXX_PURE
00039 //   _GLIBCXX_CONST
00040 //   _GLIBCXX_NORETURN
00041 //   _GLIBCXX_NOTHROW
00042 //   _GLIBCXX_VISIBILITY
00043 #ifndef _GLIBCXX_PURE
00044 # define _GLIBCXX_PURE __attribute__ ((__pure__))
00045 #endif
00046 
00047 #ifndef _GLIBCXX_CONST
00048 # define _GLIBCXX_CONST __attribute__ ((__const__))
00049 #endif
00050 
00051 #ifndef _GLIBCXX_NORETURN
00052 # define _GLIBCXX_NORETURN __attribute__ ((__noreturn__))
00053 #endif
00054 
00055 #ifndef _GLIBCXX_NOTHROW
00056 # ifdef __cplusplus
00057 #  define _GLIBCXX_NOTHROW throw()
00058 # else
00059 #  define _GLIBCXX_NOTHROW __attribute__((__nothrow__))
00060 # endif
00061 #endif
00062 
00063 // Macros for visibility attributes.
00064 //   _GLIBCXX_HAVE_ATTRIBUTE_VISIBILITY
00065 //   _GLIBCXX_VISIBILITY
00066 # define _GLIBCXX_HAVE_ATTRIBUTE_VISIBILITY 1
00067 
00068 #if _GLIBCXX_HAVE_ATTRIBUTE_VISIBILITY
00069 # define _GLIBCXX_VISIBILITY(V) __attribute__ ((__visibility__ (#V)))
00070 #else
00071 // If this is not supplied by the OS-specific or CPU-specific
00072 // headers included below, it will be defined to an empty default.
00073 # define _GLIBCXX_VISIBILITY(V) _GLIBCXX_PSEUDO_VISIBILITY(V)
00074 #endif
00075 
00076 // Macros for deprecated attributes.
00077 //   _GLIBCXX_USE_DEPRECATED
00078 //   _GLIBCXX_DEPRECATED
00079 #ifndef _GLIBCXX_USE_DEPRECATED
00080 # define _GLIBCXX_USE_DEPRECATED 1
00081 #endif
00082 
00083 #if defined(__DEPRECATED) && defined(__GXX_EXPERIMENTAL_CXX0X__)
00084 # define _GLIBCXX_DEPRECATED __attribute__ ((__deprecated__))
00085 #else
00086 # define _GLIBCXX_DEPRECATED
00087 #endif
00088 
00089 #if __cplusplus
00090 
00091 // Macro for constexpr, to support in mixed 03/0x mode.
00092 #ifndef _GLIBCXX_CONSTEXPR
00093 # ifdef __GXX_EXPERIMENTAL_CXX0X__
00094 #  define _GLIBCXX_CONSTEXPR constexpr
00095 #  define _GLIBCXX_USE_CONSTEXPR constexpr
00096 # else
00097 #  define _GLIBCXX_CONSTEXPR
00098 #  define _GLIBCXX_USE_CONSTEXPR const
00099 # endif
00100 #endif
00101 
00102 // Macro for extern template, ie controling template linkage via use
00103 // of extern keyword on template declaration. As documented in the g++
00104 // manual, it inhibits all implicit instantiations and is used
00105 // throughout the library to avoid multiple weak definitions for
00106 // required types that are already explicitly instantiated in the
00107 // library binary. This substantially reduces the binary size of
00108 // resulting executables.
00109 // Special case: _GLIBCXX_EXTERN_TEMPLATE == -1 disallows extern
00110 // templates only in basic_string, thus activating its debug-mode
00111 // checks even at -O0.
00112 # define _GLIBCXX_EXTERN_TEMPLATE 1
00113 
00114 /*
00115   Outline of libstdc++ namespaces.
00116 
00117   namespace std
00118   {
00119     namespace __debug { }
00120     namespace __parallel { }
00121     namespace __profile { }
00122     namespace __cxx1998 { }
00123 
00124     namespace __detail { }
00125 
00126     namespace rel_ops { }
00127 
00128     namespace tr1
00129     {
00130       namespace placeholders { }
00131       namespace regex_constants { }
00132       namespace __detail { }
00133     }
00134 
00135     namespace decimal { }
00136 
00137     namespace chrono { }
00138     namespace placeholders { }
00139     namespace regex_constants { }
00140     namespace this_thread { }
00141   }
00142 
00143   namespace abi { }
00144 
00145   namespace __gnu_cxx
00146   {
00147     namespace __detail { }
00148   }
00149 
00150   For full details see:
00151   http://gcc.gnu.org/onlinedocs/libstdc++/latest-doxygen/namespaces.html
00152 */
00153 namespace std
00154 {
00155   typedef __SIZE_TYPE__     size_t;
00156   typedef __PTRDIFF_TYPE__  ptrdiff_t;
00157 
00158 #ifdef __GXX_EXPERIMENTAL_CXX0X__
00159   typedef decltype(nullptr) nullptr_t;
00160 #endif
00161 }
00162 
00163 
00164 // Defined if inline namespaces are used for versioning.
00165 # define _GLIBCXX_INLINE_VERSION 0 
00166 
00167 // Inline namespace for symbol versioning.
00168 #if _GLIBCXX_INLINE_VERSION
00169 
00170 namespace std
00171 {
00172   inline namespace __7 { }
00173 
00174   namespace rel_ops { inline namespace __7 { } }
00175 
00176   namespace tr1
00177   {
00178     inline namespace __7 { }
00179     namespace placeholders { inline namespace __7 { } }
00180     namespace regex_constants { inline namespace __7 { } }
00181     namespace __detail { inline namespace __7 { } }
00182   }
00183 
00184   namespace decimal { inline namespace __7 { } }
00185 
00186   namespace chrono { inline namespace __7 { } }
00187   namespace placeholders { inline namespace __7 { } }
00188   namespace regex_constants { inline namespace __7 { } }
00189   namespace this_thread { inline namespace __7 { } }
00190 
00191   namespace __detail { inline namespace __7 { } }
00192   namespace __regex { inline namespace __7 { } }
00193 }
00194 
00195 namespace __gnu_cxx
00196 {
00197   inline namespace __7 { }
00198   namespace __detail { inline namespace __7 { } }
00199 }
00200 # define _GLIBCXX_BEGIN_NAMESPACE_VERSION namespace __7 {
00201 # define _GLIBCXX_END_NAMESPACE_VERSION }
00202 #else
00203 # define _GLIBCXX_BEGIN_NAMESPACE_VERSION
00204 # define _GLIBCXX_END_NAMESPACE_VERSION
00205 #endif
00206 
00207 
00208 // Inline namespaces for special modes: debug, parallel, profile.
00209 #if defined(_GLIBCXX_DEBUG) || defined(_GLIBCXX_PARALLEL) \
00210     || defined(_GLIBCXX_PROFILE)
00211 namespace std
00212 {
00213   // Non-inline namespace for components replaced by alternates in active mode.
00214   namespace __cxx1998
00215   {
00216 #if _GLIBCXX_INLINE_VERSION
00217  inline namespace __7 { }
00218 #endif
00219   }
00220 
00221   // Inline namespace for debug mode.
00222 # ifdef _GLIBCXX_DEBUG
00223   inline namespace __debug { }
00224 # endif
00225 
00226   // Inline namespaces for parallel mode.
00227 # ifdef _GLIBCXX_PARALLEL
00228   inline namespace __parallel { }
00229 # endif
00230 
00231   // Inline namespaces for profile mode
00232 # ifdef _GLIBCXX_PROFILE
00233   inline namespace __profile { }
00234 # endif
00235 }
00236 
00237 // Check for invalid usage and unsupported mixed-mode use.
00238 # if defined(_GLIBCXX_DEBUG) && defined(_GLIBCXX_PARALLEL)
00239 #  error illegal use of multiple inlined namespaces
00240 # endif
00241 # if defined(_GLIBCXX_PROFILE) && defined(_GLIBCXX_DEBUG)
00242 #  error illegal use of multiple inlined namespaces
00243 # endif
00244 # if defined(_GLIBCXX_PROFILE) && defined(_GLIBCXX_PARALLEL)
00245 #  error illegal use of multiple inlined namespaces
00246 # endif
00247 
00248 // Check for invalid use due to lack for weak symbols.
00249 # if __NO_INLINE__ && !__GXX_WEAK__
00250 #  warning currently using inlined namespace mode which may fail \
00251    without inlining due to lack of weak symbols
00252 # endif
00253 #endif
00254 
00255 // Macros for namespace scope. Either namespace std:: or the name
00256 // of some nested namespace within it corresponding to the active mode.
00257 // _GLIBCXX_STD_A
00258 // _GLIBCXX_STD_C
00259 //
00260 // Macros for opening/closing conditional namespaces.
00261 // _GLIBCXX_BEGIN_NAMESPACE_ALGO
00262 // _GLIBCXX_END_NAMESPACE_ALGO
00263 // _GLIBCXX_BEGIN_NAMESPACE_CONTAINER
00264 // _GLIBCXX_END_NAMESPACE_CONTAINER
00265 #if defined(_GLIBCXX_DEBUG) || defined(_GLIBCXX_PROFILE)
00266 # define _GLIBCXX_STD_C __cxx1998
00267 # define _GLIBCXX_BEGIN_NAMESPACE_CONTAINER \
00268      namespace _GLIBCXX_STD_C { _GLIBCXX_BEGIN_NAMESPACE_VERSION
00269 # define _GLIBCXX_END_NAMESPACE_CONTAINER \
00270      } _GLIBCXX_END_NAMESPACE_VERSION
00271 # undef _GLIBCXX_EXTERN_TEMPLATE
00272 #  define _GLIBCXX_EXTERN_TEMPLATE 1 -1
00273 #endif
00274 
00275 #ifdef _GLIBCXX_PARALLEL
00276 # define _GLIBCXX_STD_A __cxx1998
00277 # define _GLIBCXX_BEGIN_NAMESPACE_ALGO \
00278      namespace _GLIBCXX_STD_A { _GLIBCXX_BEGIN_NAMESPACE_VERSION
00279 # define _GLIBCXX_END_NAMESPACE_ALGO \
00280      } _GLIBCXX_END_NAMESPACE_VERSION
00281 #endif
00282 
00283 #ifndef _GLIBCXX_STD_A
00284 # define _GLIBCXX_STD_A std
00285 #endif
00286 
00287 #ifndef _GLIBCXX_STD_C
00288 # define _GLIBCXX_STD_C std
00289 #endif
00290 
00291 #ifndef _GLIBCXX_BEGIN_NAMESPACE_ALGO
00292 # define _GLIBCXX_BEGIN_NAMESPACE_ALGO
00293 #endif
00294 
00295 #ifndef _GLIBCXX_END_NAMESPACE_ALGO
00296 # define _GLIBCXX_END_NAMESPACE_ALGO
00297 #endif
00298 
00299 #ifndef _GLIBCXX_BEGIN_NAMESPACE_CONTAINER
00300 # define _GLIBCXX_BEGIN_NAMESPACE_CONTAINER
00301 #endif
00302 
00303 #ifndef _GLIBCXX_END_NAMESPACE_CONTAINER
00304 # define _GLIBCXX_END_NAMESPACE_CONTAINER
00305 #endif
00306 
00307 // GLIBCXX_ABI Deprecated
00308 // Define if compatibility should be provided for -mlong-double-64.
00309 #undef _GLIBCXX_LONG_DOUBLE_COMPAT
00310 
00311 // Inline namespace for long double 128 mode.
00312 #if defined _GLIBCXX_LONG_DOUBLE_COMPAT && defined __LONG_DOUBLE_128__
00313 namespace std
00314 {
00315   inline namespace __gnu_cxx_ldbl128 { }
00316 }
00317 # define _GLIBCXX_NAMESPACE_LDBL __gnu_cxx_ldbl128::
00318 # define _GLIBCXX_BEGIN_NAMESPACE_LDBL namespace __gnu_cxx_ldbl128 {
00319 # define _GLIBCXX_END_NAMESPACE_LDBL }
00320 #else
00321 # define _GLIBCXX_NAMESPACE_LDBL
00322 # define _GLIBCXX_BEGIN_NAMESPACE_LDBL
00323 # define _GLIBCXX_END_NAMESPACE_LDBL
00324 #endif
00325 
00326 // Assert.
00327 #if !defined(_GLIBCXX_DEBUG) && !defined(_GLIBCXX_PARALLEL)
00328 # define __glibcxx_assert(_Condition)
00329 #else
00330 namespace std
00331 {
00332   // Avoid the use of assert, because we're trying to keep the <cassert>
00333   // include out of the mix.
00334   inline void
00335   __replacement_assert(const char* __file, int __line,
00336                const char* __function, const char* __condition)
00337   {
00338     __builtin_printf("%s:%d: %s: Assertion '%s' failed.\n", __file, __line,
00339              __function, __condition);
00340     __builtin_abort();
00341   }
00342 }
00343 #define __glibcxx_assert(_Condition)                     \
00344   do                                     \
00345   {                                      \
00346     if (! (_Condition))                                                  \
00347       std::__replacement_assert(__FILE__, __LINE__, __PRETTY_FUNCTION__, \
00348                 #_Condition);                \
00349   } while (false)
00350 #endif
00351 
00352 // Macros for race detectors.
00353 // _GLIBCXX_SYNCHRONIZATION_HAPPENS_BEFORE(A) and
00354 // _GLIBCXX_SYNCHRONIZATION_HAPPENS_AFTER(A) should be used to explain
00355 // atomic (lock-free) synchronization to race detectors:
00356 // the race detector will infer a happens-before arc from the former to the
00357 // latter when they share the same argument pointer.
00358 //
00359 // The most frequent use case for these macros (and the only case in the
00360 // current implementation of the library) is atomic reference counting:
00361 //   void _M_remove_reference()
00362 //   {
00363 //     _GLIBCXX_SYNCHRONIZATION_HAPPENS_BEFORE(&this->_M_refcount);
00364 //     if (__gnu_cxx::__exchange_and_add_dispatch(&this->_M_refcount, -1) <= 0)
00365 //       {
00366 //         _GLIBCXX_SYNCHRONIZATION_HAPPENS_AFTER(&this->_M_refcount);
00367 //         _M_destroy(__a);
00368 //       }
00369 //   }
00370 // The annotations in this example tell the race detector that all memory
00371 // accesses occurred when the refcount was positive do not race with
00372 // memory accesses which occurred after the refcount became zero.
00373 #ifndef _GLIBCXX_SYNCHRONIZATION_HAPPENS_BEFORE
00374 # define  _GLIBCXX_SYNCHRONIZATION_HAPPENS_BEFORE(A)
00375 #endif
00376 #ifndef _GLIBCXX_SYNCHRONIZATION_HAPPENS_AFTER
00377 # define  _GLIBCXX_SYNCHRONIZATION_HAPPENS_AFTER(A)
00378 #endif
00379 
00380 // Macros for C linkage: define extern "C" linkage only when using C++.
00381 # define _GLIBCXX_BEGIN_EXTERN_C extern "C" {
00382 # define _GLIBCXX_END_EXTERN_C }
00383 
00384 #else // !__cplusplus
00385 # define _GLIBCXX_BEGIN_EXTERN_C
00386 # define _GLIBCXX_END_EXTERN_C
00387 #endif
00388 
00389 
00390 // First includes.
00391 
00392 // Pick up any OS-specific definitions.
00393 #include <bits/os_defines.h>
00394 
00395 // Pick up any CPU-specific definitions.
00396 #include <bits/cpu_defines.h>
00397 
00398 // If platform uses neither visibility nor psuedo-visibility,
00399 // specify empty default for namespace annotation macros.
00400 #ifndef _GLIBCXX_PSEUDO_VISIBILITY
00401 # define _GLIBCXX_PSEUDO_VISIBILITY(V)
00402 #endif
00403 
00404 // Certain function definitions that are meant to be overridable from
00405 // user code are decorated with this macro.  For some targets, this
00406 // macro causes these definitions to be weak.
00407 #ifndef _GLIBCXX_WEAK_DEFINITION
00408 # define _GLIBCXX_WEAK_DEFINITION
00409 #endif
00410 
00411 
00412 // The remainder of the prewritten config is automatic; all the
00413 // user hooks are listed above.
00414 
00415 // Create a boolean flag to be used to determine if --fast-math is set.
00416 #ifdef __FAST_MATH__
00417 # define _GLIBCXX_FAST_MATH 1
00418 #else
00419 # define _GLIBCXX_FAST_MATH 0
00420 #endif
00421 
00422 // This marks string literals in header files to be extracted for eventual
00423 // translation.  It is primarily used for messages in thrown exceptions; see
00424 // src/functexcept.cc.  We use __N because the more traditional _N is used
00425 // for something else under certain OSes (see BADNAMES).
00426 #define __N(msgid)     (msgid)
00427 
00428 // For example, <windows.h> is known to #define min and max as macros...
00429 #undef min
00430 #undef max
00431 
00432 // End of prewritten config; the settings discovered at configure time follow.
00433 /* config.h.  Generated from config.h.in by configure.  */
00434 /* config.h.in.  Generated from configure.ac by autoheader.  */
00435 
00436 /* Define to 1 if you have the `acosf' function. */
00437 #define _GLIBCXX_HAVE_ACOSF 1
00438 
00439 /* Define to 1 if you have the `acosl' function. */
00440 #define _GLIBCXX_HAVE_ACOSL 1
00441 
00442 /* Define to 1 if you have the `asinf' function. */
00443 #define _GLIBCXX_HAVE_ASINF 1
00444 
00445 /* Define to 1 if you have the `asinl' function. */
00446 #define _GLIBCXX_HAVE_ASINL 1
00447 
00448 /* Define to 1 if the target assembler supports .symver directive. */
00449 #define _GLIBCXX_HAVE_AS_SYMVER_DIRECTIVE 1
00450 
00451 /* Define to 1 if you have the `atan2f' function. */
00452 #define _GLIBCXX_HAVE_ATAN2F 1
00453 
00454 /* Define to 1 if you have the `atan2l' function. */
00455 #define _GLIBCXX_HAVE_ATAN2L 1
00456 
00457 /* Define to 1 if you have the `atanf' function. */
00458 #define _GLIBCXX_HAVE_ATANF 1
00459 
00460 /* Define to 1 if you have the `atanl' function. */
00461 #define _GLIBCXX_HAVE_ATANL 1
00462 
00463 /* Define to 1 if the target assembler supports thread-local storage. */
00464 /* #undef _GLIBCXX_HAVE_CC_TLS */
00465 
00466 /* Define to 1 if you have the `ceilf' function. */
00467 #define _GLIBCXX_HAVE_CEILF 1
00468 
00469 /* Define to 1 if you have the `ceill' function. */
00470 #define _GLIBCXX_HAVE_CEILL 1
00471 
00472 /* Define to 1 if you have the <complex.h> header file. */
00473 #define _GLIBCXX_HAVE_COMPLEX_H 1
00474 
00475 /* Define to 1 if you have the `cosf' function. */
00476 #define _GLIBCXX_HAVE_COSF 1
00477 
00478 /* Define to 1 if you have the `coshf' function. */
00479 #define _GLIBCXX_HAVE_COSHF 1
00480 
00481 /* Define to 1 if you have the `coshl' function. */
00482 #define _GLIBCXX_HAVE_COSHL 1
00483 
00484 /* Define to 1 if you have the `cosl' function. */
00485 #define _GLIBCXX_HAVE_COSL 1
00486 
00487 /* Define to 1 if you have the <dlfcn.h> header file. */
00488 #define _GLIBCXX_HAVE_DLFCN_H 1
00489 
00490 /* Define if EBADMSG exists. */
00491 #define _GLIBCXX_HAVE_EBADMSG 1
00492 
00493 /* Define if ECANCELED exists. */
00494 #define _GLIBCXX_HAVE_ECANCELED 1
00495 
00496 /* Define if EIDRM exists. */
00497 #define _GLIBCXX_HAVE_EIDRM 1
00498 
00499 /* Define to 1 if you have the <endian.h> header file. */
00500 #define _GLIBCXX_HAVE_ENDIAN_H 1
00501 
00502 /* Define if ENODATA exists. */
00503 #define _GLIBCXX_HAVE_ENODATA 1
00504 
00505 /* Define if ENOLINK exists. */
00506 #define _GLIBCXX_HAVE_ENOLINK 1
00507 
00508 /* Define if ENOSR exists. */
00509 #define _GLIBCXX_HAVE_ENOSR 1
00510 
00511 /* Define if ENOSTR exists. */
00512 #define _GLIBCXX_HAVE_ENOSTR 1
00513 
00514 /* Define if ENOTRECOVERABLE exists. */
00515 #define _GLIBCXX_HAVE_ENOTRECOVERABLE 1
00516 
00517 /* Define if ENOTSUP exists. */
00518 #define _GLIBCXX_HAVE_ENOTSUP 1
00519 
00520 /* Define if EOVERFLOW exists. */
00521 #define _GLIBCXX_HAVE_EOVERFLOW 1
00522 
00523 /* Define if EOWNERDEAD exists. */
00524 #define _GLIBCXX_HAVE_EOWNERDEAD 1
00525 
00526 /* Define if EPROTO exists. */
00527 #define _GLIBCXX_HAVE_EPROTO 1
00528 
00529 /* Define if ETIME exists. */
00530 #define _GLIBCXX_HAVE_ETIME 1
00531 
00532 /* Define if ETXTBSY exists. */
00533 #define _GLIBCXX_HAVE_ETXTBSY 1
00534 
00535 /* Define to 1 if you have the <execinfo.h> header file. */
00536 #define _GLIBCXX_HAVE_EXECINFO_H 1
00537 
00538 /* Define to 1 if you have the `expf' function. */
00539 #define _GLIBCXX_HAVE_EXPF 1
00540 
00541 /* Define to 1 if you have the `expl' function. */
00542 #define _GLIBCXX_HAVE_EXPL 1
00543 
00544 /* Define to 1 if you have the `fabsf' function. */
00545 #define _GLIBCXX_HAVE_FABSF 1
00546 
00547 /* Define to 1 if you have the `fabsl' function. */
00548 #define _GLIBCXX_HAVE_FABSL 1
00549 
00550 /* Define to 1 if you have the <fenv.h> header file. */
00551 #define _GLIBCXX_HAVE_FENV_H 1
00552 
00553 /* Define to 1 if you have the `finite' function. */
00554 #define _GLIBCXX_HAVE_FINITE 1
00555 
00556 /* Define to 1 if you have the `finitef' function. */
00557 #define _GLIBCXX_HAVE_FINITEF 1
00558 
00559 /* Define to 1 if you have the `finitel' function. */
00560 #define _GLIBCXX_HAVE_FINITEL 1
00561 
00562 /* Define to 1 if you have the <float.h> header file. */
00563 #define _GLIBCXX_HAVE_FLOAT_H 1
00564 
00565 /* Define to 1 if you have the `floorf' function. */
00566 #define _GLIBCXX_HAVE_FLOORF 1
00567 
00568 /* Define to 1 if you have the `floorl' function. */
00569 #define _GLIBCXX_HAVE_FLOORL 1
00570 
00571 /* Define to 1 if you have the `fmodf' function. */
00572 #define _GLIBCXX_HAVE_FMODF 1
00573 
00574 /* Define to 1 if you have the `fmodl' function. */
00575 #define _GLIBCXX_HAVE_FMODL 1
00576 
00577 /* Define to 1 if you have the `fpclass' function. */
00578 /* #undef _GLIBCXX_HAVE_FPCLASS */
00579 
00580 /* Define to 1 if you have the <fp.h> header file. */
00581 /* #undef _GLIBCXX_HAVE_FP_H */
00582 
00583 /* Define to 1 if you have the `frexpf' function. */
00584 #define _GLIBCXX_HAVE_FREXPF 1
00585 
00586 /* Define to 1 if you have the `frexpl' function. */
00587 #define _GLIBCXX_HAVE_FREXPL 1
00588 
00589 /* Define if _Unwind_GetIPInfo is available. */
00590 #define _GLIBCXX_HAVE_GETIPINFO 1
00591 
00592 /* Define if gthr-default.h exists (meaning that threading support is
00593    enabled). */
00594 #define _GLIBCXX_HAVE_GTHR_DEFAULT 1
00595 
00596 /* Define to 1 if you have the `hypot' function. */
00597 #define _GLIBCXX_HAVE_HYPOT 1
00598 
00599 /* Define to 1 if you have the `hypotf' function. */
00600 #define _GLIBCXX_HAVE_HYPOTF 1
00601 
00602 /* Define to 1 if you have the `hypotl' function. */
00603 #define _GLIBCXX_HAVE_HYPOTL 1
00604 
00605 /* Define if you have the iconv() function. */
00606 #define _GLIBCXX_HAVE_ICONV 1
00607 
00608 /* Define to 1 if you have the <ieeefp.h> header file. */
00609 /* #undef _GLIBCXX_HAVE_IEEEFP_H */
00610 
00611 /* Define if int64_t is available in <stdint.h>. */
00612 #define _GLIBCXX_HAVE_INT64_T 1
00613 
00614 /* Define if int64_t is a long. */
00615 #define _GLIBCXX_HAVE_INT64_T_LONG 1
00616 
00617 /* Define if int64_t is a long long. */
00618 /* #undef _GLIBCXX_HAVE_INT64_T_LONG_LONG */
00619 
00620 /* Define to 1 if you have the <inttypes.h> header file. */
00621 #define _GLIBCXX_HAVE_INTTYPES_H 1
00622 
00623 /* Define to 1 if you have the `isinf' function. */
00624 #define _GLIBCXX_HAVE_ISINF 1
00625 
00626 /* Define to 1 if you have the `isinff' function. */
00627 #define _GLIBCXX_HAVE_ISINFF 1
00628 
00629 /* Define to 1 if you have the `isinfl' function. */
00630 #define _GLIBCXX_HAVE_ISINFL 1
00631 
00632 /* Define to 1 if you have the `isnan' function. */
00633 #define _GLIBCXX_HAVE_ISNAN 1
00634 
00635 /* Define to 1 if you have the `isnanf' function. */
00636 #define _GLIBCXX_HAVE_ISNANF 1
00637 
00638 /* Define to 1 if you have the `isnanl' function. */
00639 #define _GLIBCXX_HAVE_ISNANL 1
00640 
00641 /* Defined if iswblank exists. */
00642 #define _GLIBCXX_HAVE_ISWBLANK 1
00643 
00644 /* Define if LC_MESSAGES is available in <locale.h>. */
00645 #define _GLIBCXX_HAVE_LC_MESSAGES 1
00646 
00647 /* Define to 1 if you have the `ldexpf' function. */
00648 #define _GLIBCXX_HAVE_LDEXPF 1
00649 
00650 /* Define to 1 if you have the `ldexpl' function. */
00651 #define _GLIBCXX_HAVE_LDEXPL 1
00652 
00653 /* Define to 1 if you have the <libintl.h> header file. */
00654 #define _GLIBCXX_HAVE_LIBINTL_H 1
00655 
00656 /* Only used in build directory testsuite_hooks.h. */
00657 #define _GLIBCXX_HAVE_LIMIT_AS 1
00658 
00659 /* Only used in build directory testsuite_hooks.h. */
00660 #define _GLIBCXX_HAVE_LIMIT_DATA 1
00661 
00662 /* Only used in build directory testsuite_hooks.h. */
00663 #define _GLIBCXX_HAVE_LIMIT_FSIZE 1
00664 
00665 /* Only used in build directory testsuite_hooks.h. */
00666 #define _GLIBCXX_HAVE_LIMIT_RSS 1
00667 
00668 /* Only used in build directory testsuite_hooks.h. */
00669 #define _GLIBCXX_HAVE_LIMIT_VMEM 0
00670 
00671 /* Define if futex syscall is available. */
00672 #define _GLIBCXX_HAVE_LINUX_FUTEX 1
00673 
00674 /* Define to 1 if you have the <locale.h> header file. */
00675 #define _GLIBCXX_HAVE_LOCALE_H 1
00676 
00677 /* Define to 1 if you have the `log10f' function. */
00678 #define _GLIBCXX_HAVE_LOG10F 1
00679 
00680 /* Define to 1 if you have the `log10l' function. */
00681 #define _GLIBCXX_HAVE_LOG10L 1
00682 
00683 /* Define to 1 if you have the `logf' function. */
00684 #define _GLIBCXX_HAVE_LOGF 1
00685 
00686 /* Define to 1 if you have the `logl' function. */
00687 #define _GLIBCXX_HAVE_LOGL 1
00688 
00689 /* Define to 1 if you have the <machine/endian.h> header file. */
00690 /* #undef _GLIBCXX_HAVE_MACHINE_ENDIAN_H */
00691 
00692 /* Define to 1 if you have the <machine/param.h> header file. */
00693 /* #undef _GLIBCXX_HAVE_MACHINE_PARAM_H */
00694 
00695 /* Define if mbstate_t exists in wchar.h. */
00696 #define _GLIBCXX_HAVE_MBSTATE_T 1
00697 
00698 /* Define to 1 if you have the <memory.h> header file. */
00699 #define _GLIBCXX_HAVE_MEMORY_H 1
00700 
00701 /* Define to 1 if you have the `modf' function. */
00702 #define _GLIBCXX_HAVE_MODF 1
00703 
00704 /* Define to 1 if you have the `modff' function. */
00705 #define _GLIBCXX_HAVE_MODFF 1
00706 
00707 /* Define to 1 if you have the `modfl' function. */
00708 #define _GLIBCXX_HAVE_MODFL 1
00709 
00710 /* Define to 1 if you have the <nan.h> header file. */
00711 /* #undef _GLIBCXX_HAVE_NAN_H */
00712 
00713 /* Define if poll is available in <poll.h>. */
00714 #define _GLIBCXX_HAVE_POLL 1
00715 
00716 /* Define to 1 if you have the `powf' function. */
00717 #define _GLIBCXX_HAVE_POWF 1
00718 
00719 /* Define to 1 if you have the `powl' function. */
00720 #define _GLIBCXX_HAVE_POWL 1
00721 
00722 /* Define to 1 if you have the `qfpclass' function. */
00723 /* #undef _GLIBCXX_HAVE_QFPCLASS */
00724 
00725 /* Define to 1 if you have the `setenv' function. */
00726 #define _GLIBCXX_HAVE_SETENV 1
00727 
00728 /* Define to 1 if you have the `sincos' function. */
00729 #define _GLIBCXX_HAVE_SINCOS 1
00730 
00731 /* Define to 1 if you have the `sincosf' function. */
00732 #define _GLIBCXX_HAVE_SINCOSF 1
00733 
00734 /* Define to 1 if you have the `sincosl' function. */
00735 #define _GLIBCXX_HAVE_SINCOSL 1
00736 
00737 /* Define to 1 if you have the `sinf' function. */
00738 #define _GLIBCXX_HAVE_SINF 1
00739 
00740 /* Define to 1 if you have the `sinhf' function. */
00741 #define _GLIBCXX_HAVE_SINHF 1
00742 
00743 /* Define to 1 if you have the `sinhl' function. */
00744 #define _GLIBCXX_HAVE_SINHL 1
00745 
00746 /* Define to 1 if you have the `sinl' function. */
00747 #define _GLIBCXX_HAVE_SINL 1
00748 
00749 /* Define to 1 if you have the `sqrtf' function. */
00750 #define _GLIBCXX_HAVE_SQRTF 1
00751 
00752 /* Define to 1 if you have the `sqrtl' function. */
00753 #define _GLIBCXX_HAVE_SQRTL 1
00754 
00755 /* Define to 1 if you have the <stdbool.h> header file. */
00756 #define _GLIBCXX_HAVE_STDBOOL_H 1
00757 
00758 /* Define to 1 if you have the <stdint.h> header file. */
00759 #define _GLIBCXX_HAVE_STDINT_H 1
00760 
00761 /* Define to 1 if you have the <stdlib.h> header file. */
00762 #define _GLIBCXX_HAVE_STDLIB_H 1
00763 
00764 /* Define if strerror_l is available in <string.h>. */
00765 #define _GLIBCXX_HAVE_STRERROR_L 1
00766 
00767 /* Define if strerror_r is available in <string.h>. */
00768 #define _GLIBCXX_HAVE_STRERROR_R 1
00769 
00770 /* Define to 1 if you have the <strings.h> header file. */
00771 #define _GLIBCXX_HAVE_STRINGS_H 1
00772 
00773 /* Define to 1 if you have the <string.h> header file. */
00774 #define _GLIBCXX_HAVE_STRING_H 1
00775 
00776 /* Define to 1 if you have the `strtof' function. */
00777 #define _GLIBCXX_HAVE_STRTOF 1
00778 
00779 /* Define to 1 if you have the `strtold' function. */
00780 #define _GLIBCXX_HAVE_STRTOLD 1
00781 
00782 /* Define if strxfrm_l is available in <string.h>. */
00783 #define _GLIBCXX_HAVE_STRXFRM_L 1
00784 
00785 /* Define to 1 if the target runtime linker supports binding the same symbol
00786    to different versions. */
00787 #define _GLIBCXX_HAVE_SYMVER_SYMBOL_RENAMING_RUNTIME_SUPPORT 1
00788 
00789 /* Define to 1 if you have the <sys/filio.h> header file. */
00790 /* #undef _GLIBCXX_HAVE_SYS_FILIO_H */
00791 
00792 /* Define to 1 if you have the <sys/ioctl.h> header file. */
00793 #define _GLIBCXX_HAVE_SYS_IOCTL_H 1
00794 
00795 /* Define to 1 if you have the <sys/ipc.h> header file. */
00796 #define _GLIBCXX_HAVE_SYS_IPC_H 1
00797 
00798 /* Define to 1 if you have the <sys/isa_defs.h> header file. */
00799 /* #undef _GLIBCXX_HAVE_SYS_ISA_DEFS_H */
00800 
00801 /* Define to 1 if you have the <sys/machine.h> header file. */
00802 /* #undef _GLIBCXX_HAVE_SYS_MACHINE_H */
00803 
00804 /* Define to 1 if you have the <sys/param.h> header file. */
00805 #define _GLIBCXX_HAVE_SYS_PARAM_H 1
00806 
00807 /* Define to 1 if you have the <sys/resource.h> header file. */
00808 #define _GLIBCXX_HAVE_SYS_RESOURCE_H 1
00809 
00810 /* Define to 1 if you have the <sys/sem.h> header file. */
00811 #define _GLIBCXX_HAVE_SYS_SEM_H 1
00812 
00813 /* Define to 1 if you have the <sys/stat.h> header file. */
00814 #define _GLIBCXX_HAVE_SYS_STAT_H 1
00815 
00816 /* Define to 1 if you have the <sys/time.h> header file. */
00817 #define _GLIBCXX_HAVE_SYS_TIME_H 1
00818 
00819 /* Define to 1 if you have the <sys/types.h> header file. */
00820 #define _GLIBCXX_HAVE_SYS_TYPES_H 1
00821 
00822 /* Define to 1 if you have the <sys/uio.h> header file. */
00823 #define _GLIBCXX_HAVE_SYS_UIO_H 1
00824 
00825 /* Define if S_IFREG is available in <sys/stat.h>. */
00826 /* #undef _GLIBCXX_HAVE_S_IFREG */
00827 
00828 /* Define if S_IFREG is available in <sys/stat.h>. */
00829 #define _GLIBCXX_HAVE_S_ISREG 1
00830 
00831 /* Define to 1 if you have the `tanf' function. */
00832 #define _GLIBCXX_HAVE_TANF 1
00833 
00834 /* Define to 1 if you have the `tanhf' function. */
00835 #define _GLIBCXX_HAVE_TANHF 1
00836 
00837 /* Define to 1 if you have the `tanhl' function. */
00838 #define _GLIBCXX_HAVE_TANHL 1
00839 
00840 /* Define to 1 if you have the `tanl' function. */
00841 #define _GLIBCXX_HAVE_TANL 1
00842 
00843 /* Define to 1 if you have the <tgmath.h> header file. */
00844 #define _GLIBCXX_HAVE_TGMATH_H 1
00845 
00846 /* Define to 1 if the target supports thread-local storage. */
00847 #define _GLIBCXX_HAVE_TLS 1
00848 
00849 /* Define to 1 if you have the <unistd.h> header file. */
00850 #define _GLIBCXX_HAVE_UNISTD_H 1
00851 
00852 /* Defined if vfwscanf exists. */
00853 #define _GLIBCXX_HAVE_VFWSCANF 1
00854 
00855 /* Defined if vswscanf exists. */
00856 #define _GLIBCXX_HAVE_VSWSCANF 1
00857 
00858 /* Defined if vwscanf exists. */
00859 #define _GLIBCXX_HAVE_VWSCANF 1
00860 
00861 /* Define to 1 if you have the <wchar.h> header file. */
00862 #define _GLIBCXX_HAVE_WCHAR_H 1
00863 
00864 /* Defined if wcstof exists. */
00865 #define _GLIBCXX_HAVE_WCSTOF 1
00866 
00867 /* Define to 1 if you have the <wctype.h> header file. */
00868 #define _GLIBCXX_HAVE_WCTYPE_H 1
00869 
00870 /* Define if writev is available in <sys/uio.h>. */
00871 #define _GLIBCXX_HAVE_WRITEV 1
00872 
00873 /* Define to 1 if you have the `_acosf' function. */
00874 /* #undef _GLIBCXX_HAVE__ACOSF */
00875 
00876 /* Define to 1 if you have the `_acosl' function. */
00877 /* #undef _GLIBCXX_HAVE__ACOSL */
00878 
00879 /* Define to 1 if you have the `_asinf' function. */
00880 /* #undef _GLIBCXX_HAVE__ASINF */
00881 
00882 /* Define to 1 if you have the `_asinl' function. */
00883 /* #undef _GLIBCXX_HAVE__ASINL */
00884 
00885 /* Define to 1 if you have the `_atan2f' function. */
00886 /* #undef _GLIBCXX_HAVE__ATAN2F */
00887 
00888 /* Define to 1 if you have the `_atan2l' function. */
00889 /* #undef _GLIBCXX_HAVE__ATAN2L */
00890 
00891 /* Define to 1 if you have the `_atanf' function. */
00892 /* #undef _GLIBCXX_HAVE__ATANF */
00893 
00894 /* Define to 1 if you have the `_atanl' function. */
00895 /* #undef _GLIBCXX_HAVE__ATANL */
00896 
00897 /* Define to 1 if you have the `_ceilf' function. */
00898 /* #undef _GLIBCXX_HAVE__CEILF */
00899 
00900 /* Define to 1 if you have the `_ceill' function. */
00901 /* #undef _GLIBCXX_HAVE__CEILL */
00902 
00903 /* Define to 1 if you have the `_cosf' function. */
00904 /* #undef _GLIBCXX_HAVE__COSF */
00905 
00906 /* Define to 1 if you have the `_coshf' function. */
00907 /* #undef _GLIBCXX_HAVE__COSHF */
00908 
00909 /* Define to 1 if you have the `_coshl' function. */
00910 /* #undef _GLIBCXX_HAVE__COSHL */
00911 
00912 /* Define to 1 if you have the `_cosl' function. */
00913 /* #undef _GLIBCXX_HAVE__COSL */
00914 
00915 /* Define to 1 if you have the `_expf' function. */
00916 /* #undef _GLIBCXX_HAVE__EXPF */
00917 
00918 /* Define to 1 if you have the `_expl' function. */
00919 /* #undef _GLIBCXX_HAVE__EXPL */
00920 
00921 /* Define to 1 if you have the `_fabsf' function. */
00922 /* #undef _GLIBCXX_HAVE__FABSF */
00923 
00924 /* Define to 1 if you have the `_fabsl' function. */
00925 /* #undef _GLIBCXX_HAVE__FABSL */
00926 
00927 /* Define to 1 if you have the `_finite' function. */
00928 /* #undef _GLIBCXX_HAVE__FINITE */
00929 
00930 /* Define to 1 if you have the `_finitef' function. */
00931 /* #undef _GLIBCXX_HAVE__FINITEF */
00932 
00933 /* Define to 1 if you have the `_finitel' function. */
00934 /* #undef _GLIBCXX_HAVE__FINITEL */
00935 
00936 /* Define to 1 if you have the `_floorf' function. */
00937 /* #undef _GLIBCXX_HAVE__FLOORF */
00938 
00939 /* Define to 1 if you have the `_floorl' function. */
00940 /* #undef _GLIBCXX_HAVE__FLOORL */
00941 
00942 /* Define to 1 if you have the `_fmodf' function. */
00943 /* #undef _GLIBCXX_HAVE__FMODF */
00944 
00945 /* Define to 1 if you have the `_fmodl' function. */
00946 /* #undef _GLIBCXX_HAVE__FMODL */
00947 
00948 /* Define to 1 if you have the `_fpclass' function. */
00949 /* #undef _GLIBCXX_HAVE__FPCLASS */
00950 
00951 /* Define to 1 if you have the `_frexpf' function. */
00952 /* #undef _GLIBCXX_HAVE__FREXPF */
00953 
00954 /* Define to 1 if you have the `_frexpl' function. */
00955 /* #undef _GLIBCXX_HAVE__FREXPL */
00956 
00957 /* Define to 1 if you have the `_hypot' function. */
00958 /* #undef _GLIBCXX_HAVE__HYPOT */
00959 
00960 /* Define to 1 if you have the `_hypotf' function. */
00961 /* #undef _GLIBCXX_HAVE__HYPOTF */
00962 
00963 /* Define to 1 if you have the `_hypotl' function. */
00964 /* #undef _GLIBCXX_HAVE__HYPOTL */
00965 
00966 /* Define to 1 if you have the `_isinf' function. */
00967 /* #undef _GLIBCXX_HAVE__ISINF */
00968 
00969 /* Define to 1 if you have the `_isinff' function. */
00970 /* #undef _GLIBCXX_HAVE__ISINFF */
00971 
00972 /* Define to 1 if you have the `_isinfl' function. */
00973 /* #undef _GLIBCXX_HAVE__ISINFL */
00974 
00975 /* Define to 1 if you have the `_isnan' function. */
00976 /* #undef _GLIBCXX_HAVE__ISNAN */
00977 
00978 /* Define to 1 if you have the `_isnanf' function. */
00979 /* #undef _GLIBCXX_HAVE__ISNANF */
00980 
00981 /* Define to 1 if you have the `_isnanl' function. */
00982 /* #undef _GLIBCXX_HAVE__ISNANL */
00983 
00984 /* Define to 1 if you have the `_ldexpf' function. */
00985 /* #undef _GLIBCXX_HAVE__LDEXPF */
00986 
00987 /* Define to 1 if you have the `_ldexpl' function. */
00988 /* #undef _GLIBCXX_HAVE__LDEXPL */
00989 
00990 /* Define to 1 if you have the `_log10f' function. */
00991 /* #undef _GLIBCXX_HAVE__LOG10F */
00992 
00993 /* Define to 1 if you have the `_log10l' function. */
00994 /* #undef _GLIBCXX_HAVE__LOG10L */
00995 
00996 /* Define to 1 if you have the `_logf' function. */
00997 /* #undef _GLIBCXX_HAVE__LOGF */
00998 
00999 /* Define to 1 if you have the `_logl' function. */
01000 /* #undef _GLIBCXX_HAVE__LOGL */
01001 
01002 /* Define to 1 if you have the `_modf' function. */
01003 /* #undef _GLIBCXX_HAVE__MODF */
01004 
01005 /* Define to 1 if you have the `_modff' function. */
01006 /* #undef _GLIBCXX_HAVE__MODFF */
01007 
01008 /* Define to 1 if you have the `_modfl' function. */
01009 /* #undef _GLIBCXX_HAVE__MODFL */
01010 
01011 /* Define to 1 if you have the `_powf' function. */
01012 /* #undef _GLIBCXX_HAVE__POWF */
01013 
01014 /* Define to 1 if you have the `_powl' function. */
01015 /* #undef _GLIBCXX_HAVE__POWL */
01016 
01017 /* Define to 1 if you have the `_qfpclass' function. */
01018 /* #undef _GLIBCXX_HAVE__QFPCLASS */
01019 
01020 /* Define to 1 if you have the `_sincos' function. */
01021 /* #undef _GLIBCXX_HAVE__SINCOS */
01022 
01023 /* Define to 1 if you have the `_sincosf' function. */
01024 /* #undef _GLIBCXX_HAVE__SINCOSF */
01025 
01026 /* Define to 1 if you have the `_sincosl' function. */
01027 /* #undef _GLIBCXX_HAVE__SINCOSL */
01028 
01029 /* Define to 1 if you have the `_sinf' function. */
01030 /* #undef _GLIBCXX_HAVE__SINF */
01031 
01032 /* Define to 1 if you have the `_sinhf' function. */
01033 /* #undef _GLIBCXX_HAVE__SINHF */
01034 
01035 /* Define to 1 if you have the `_sinhl' function. */
01036 /* #undef _GLIBCXX_HAVE__SINHL */
01037 
01038 /* Define to 1 if you have the `_sinl' function. */
01039 /* #undef _GLIBCXX_HAVE__SINL */
01040 
01041 /* Define to 1 if you have the `_sqrtf' function. */
01042 /* #undef _GLIBCXX_HAVE__SQRTF */
01043 
01044 /* Define to 1 if you have the `_sqrtl' function. */
01045 /* #undef _GLIBCXX_HAVE__SQRTL */
01046 
01047 /* Define to 1 if you have the `_tanf' function. */
01048 /* #undef _GLIBCXX_HAVE__TANF */
01049 
01050 /* Define to 1 if you have the `_tanhf' function. */
01051 /* #undef _GLIBCXX_HAVE__TANHF */
01052 
01053 /* Define to 1 if you have the `_tanhl' function. */
01054 /* #undef _GLIBCXX_HAVE__TANHL */
01055 
01056 /* Define to 1 if you have the `_tanl' function. */
01057 /* #undef _GLIBCXX_HAVE__TANL */
01058 
01059 /* Define as const if the declaration of iconv() needs const. */
01060 #define _GLIBCXX_ICONV_CONST 
01061 
01062 /* Define to the sub-directory in which libtool stores uninstalled libraries.
01063    */
01064 #define LT_OBJDIR ".libs/"
01065 
01066 /* Name of package */
01067 /* #undef _GLIBCXX_PACKAGE */
01068 
01069 /* Define to the address where bug reports for this package should be sent. */
01070 #define _GLIBCXX_PACKAGE_BUGREPORT ""
01071 
01072 /* Define to the full name of this package. */
01073 #define _GLIBCXX_PACKAGE_NAME "package-unused"
01074 
01075 /* Define to the full name and version of this package. */
01076 #define _GLIBCXX_PACKAGE_STRING "package-unused version-unused"
01077 
01078 /* Define to the one symbol short name of this package. */
01079 #define _GLIBCXX_PACKAGE_TARNAME "libstdc++"
01080 
01081 /* Define to the home page for this package. */
01082 #define _GLIBCXX_PACKAGE_URL ""
01083 
01084 /* Define to the version of this package. */
01085 #define _GLIBCXX_PACKAGE__GLIBCXX_VERSION "version-unused"
01086 
01087 /* The size of `char', as computed by sizeof. */
01088 /* #undef SIZEOF_CHAR */
01089 
01090 /* The size of `int', as computed by sizeof. */
01091 /* #undef SIZEOF_INT */
01092 
01093 /* The size of `long', as computed by sizeof. */
01094 /* #undef SIZEOF_LONG */
01095 
01096 /* The size of `short', as computed by sizeof. */
01097 /* #undef SIZEOF_SHORT */
01098 
01099 /* The size of `void *', as computed by sizeof. */
01100 /* #undef SIZEOF_VOID_P */
01101 
01102 /* Define to 1 if you have the ANSI C header files. */
01103 #define STDC_HEADERS 1
01104 
01105 /* Version number of package */
01106 /* #undef _GLIBCXX_VERSION */
01107 
01108 /* Define if builtin atomic operations for bool are supported on this host. */
01109 #define _GLIBCXX_ATOMIC_BUILTINS_1 1
01110 
01111 /* Define if builtin atomic operations for short are supported on this host.
01112    */
01113 #define _GLIBCXX_ATOMIC_BUILTINS_2 1
01114 
01115 /* Define if builtin atomic operations for int are supported on this host. */
01116 #define _GLIBCXX_ATOMIC_BUILTINS_4 1
01117 
01118 /* Define if builtin atomic operations for long long are supported on this
01119    host. */
01120 #define _GLIBCXX_ATOMIC_BUILTINS_8 1
01121 
01122 /* Define to use concept checking code from the boost libraries. */
01123 /* #undef _GLIBCXX_CONCEPT_CHECKS */
01124 
01125 /* Define if a fully dynamic basic_string is wanted. */
01126 /* #undef _GLIBCXX_FULLY_DYNAMIC_STRING */
01127 
01128 /* Define if gthreads library is available. */
01129 #define _GLIBCXX_HAS_GTHREADS 1
01130 
01131 /* Define to 1 if a full hosted library is built, or 0 if freestanding. */
01132 #define _GLIBCXX_HOSTED 1
01133 
01134 /* Define if compatibility should be provided for -mlong-double-64. */
01135 
01136 /* Define if ptrdiff_t is int. */
01137 /* #undef _GLIBCXX_PTRDIFF_T_IS_INT */
01138 
01139 /* Define if using setrlimit to set resource limits during "make check" */
01140 #define _GLIBCXX_RES_LIMITS 1
01141 
01142 /* Define if size_t is unsigned int. */
01143 /* #undef _GLIBCXX_SIZE_T_IS_UINT */
01144 
01145 /* Define if the compiler is configured for setjmp/longjmp exceptions. */
01146 /* #undef _GLIBCXX_SJLJ_EXCEPTIONS */
01147 
01148 /* Define to the value of the EOF integer constant. */
01149 #define _GLIBCXX_STDIO_EOF -1
01150 
01151 /* Define to the value of the SEEK_CUR integer constant. */
01152 #define _GLIBCXX_STDIO_SEEK_CUR 1
01153 
01154 /* Define to the value of the SEEK_END integer constant. */
01155 #define _GLIBCXX_STDIO_SEEK_END 2
01156 
01157 /* Define to use symbol versioning in the shared library. */
01158 #define _GLIBCXX_SYMVER 1
01159 
01160 /* Define to use darwin versioning in the shared library. */
01161 /* #undef _GLIBCXX_SYMVER_DARWIN */
01162 
01163 /* Define to use GNU versioning in the shared library. */
01164 #define _GLIBCXX_SYMVER_GNU 1
01165 
01166 /* Define to use GNU namespace versioning in the shared library. */
01167 /* #undef _GLIBCXX_SYMVER_GNU_NAMESPACE */
01168 
01169 /* Define to use Sun versioning in the shared library. */
01170 /* #undef _GLIBCXX_SYMVER_SUN */
01171 
01172 /* Define if C99 functions or macros from <wchar.h>, <math.h>, <complex.h>,
01173    <stdio.h>, and <stdlib.h> can be used or exposed. */
01174 #define _GLIBCXX_USE_C99 1
01175 
01176 /* Define if C99 functions in <complex.h> should be used in <complex>. Using
01177    compiler builtins for these functions requires corresponding C99 library
01178    functions to be present. */
01179 #define _GLIBCXX_USE_C99_COMPLEX 1
01180 
01181 /* Define if C99 functions in <complex.h> should be used in <tr1/complex>.
01182    Using compiler builtins for these functions requires corresponding C99
01183    library functions to be present. */
01184 #define _GLIBCXX_USE_C99_COMPLEX_TR1 1
01185 
01186 /* Define if C99 functions in <ctype.h> should be imported in <tr1/cctype> in
01187    namespace std::tr1. */
01188 #define _GLIBCXX_USE_C99_CTYPE_TR1 1
01189 
01190 /* Define if C99 functions in <fenv.h> should be imported in <tr1/cfenv> in
01191    namespace std::tr1. */
01192 #define _GLIBCXX_USE_C99_FENV_TR1 1
01193 
01194 /* Define if C99 functions in <inttypes.h> should be imported in
01195    <tr1/cinttypes> in namespace std::tr1. */
01196 #define _GLIBCXX_USE_C99_INTTYPES_TR1 1
01197 
01198 /* Define if wchar_t C99 functions in <inttypes.h> should be imported in
01199    <tr1/cinttypes> in namespace std::tr1. */
01200 #define _GLIBCXX_USE_C99_INTTYPES_WCHAR_T_TR1 1
01201 
01202 /* Define if C99 functions or macros in <math.h> should be imported in <cmath>
01203    in namespace std. */
01204 #define _GLIBCXX_USE_C99_MATH 1
01205 
01206 /* Define if C99 functions or macros in <math.h> should be imported in
01207    <tr1/cmath> in namespace std::tr1. */
01208 #define _GLIBCXX_USE_C99_MATH_TR1 1
01209 
01210 /* Define if C99 types in <stdint.h> should be imported in <tr1/cstdint> in
01211    namespace std::tr1. */
01212 #define _GLIBCXX_USE_C99_STDINT_TR1 1
01213 
01214 /* Defined if clock_gettime has monotonic clock support. */
01215 /* #undef _GLIBCXX_USE_CLOCK_MONOTONIC */
01216 
01217 /* Defined if clock_gettime has realtime clock support. */
01218 /* #undef _GLIBCXX_USE_CLOCK_REALTIME */
01219 
01220 /* Define if ISO/IEC TR 24733 decimal floating point types are supported on
01221    this host. */
01222 #define _GLIBCXX_USE_DECIMAL_FLOAT 1
01223 
01224 /* Defined if gettimeofday is available. */
01225 #define _GLIBCXX_USE_GETTIMEOFDAY 1
01226 
01227 /* Define if LFS support is available. */
01228 #define _GLIBCXX_USE_LFS 1
01229 
01230 /* Define if code specialized for long long should be used. */
01231 #define _GLIBCXX_USE_LONG_LONG 1
01232 
01233 /* Defined if nanosleep is available. */
01234 /* #undef _GLIBCXX_USE_NANOSLEEP */
01235 
01236 /* Define if NLS translations are to be used. */
01237 #define _GLIBCXX_USE_NLS 1
01238 
01239 /* Define if /dev/random and /dev/urandom are available for the random_device
01240    of TR1 (Chapter 5.1). */
01241 #define _GLIBCXX_USE_RANDOM_TR1 1
01242 
01243 /* Defined if sched_yield is available. */
01244 /* #undef _GLIBCXX_USE_SCHED_YIELD */
01245 
01246 /* Define if code specialized for wchar_t should be used. */
01247 #define _GLIBCXX_USE_WCHAR_T 1
01248 
01249 #if defined (_GLIBCXX_HAVE__ACOSF) && ! defined (_GLIBCXX_HAVE_ACOSF)
01250 # define _GLIBCXX_HAVE_ACOSF 1
01251 # define acosf _acosf
01252 #endif
01253 
01254 #if defined (_GLIBCXX_HAVE__ACOSL) && ! defined (_GLIBCXX_HAVE_ACOSL)
01255 # define _GLIBCXX_HAVE_ACOSL 1
01256 # define acosl _acosl
01257 #endif
01258 
01259 #if defined (_GLIBCXX_HAVE__ASINF) && ! defined (_GLIBCXX_HAVE_ASINF)
01260 # define _GLIBCXX_HAVE_ASINF 1
01261 # define asinf _asinf
01262 #endif
01263 
01264 #if defined (_GLIBCXX_HAVE__ASINL) && ! defined (_GLIBCXX_HAVE_ASINL)
01265 # define _GLIBCXX_HAVE_ASINL 1
01266 # define asinl _asinl
01267 #endif
01268 
01269 #if defined (_GLIBCXX_HAVE__ATAN2F) && ! defined (_GLIBCXX_HAVE_ATAN2F)
01270 # define _GLIBCXX_HAVE_ATAN2F 1
01271 # define atan2f _atan2f
01272 #endif
01273 
01274 #if defined (_GLIBCXX_HAVE__ATAN2L) && ! defined (_GLIBCXX_HAVE_ATAN2L)
01275 # define _GLIBCXX_HAVE_ATAN2L 1
01276 # define atan2l _atan2l
01277 #endif
01278 
01279 #if defined (_GLIBCXX_HAVE__ATANF) && ! defined (_GLIBCXX_HAVE_ATANF)
01280 # define _GLIBCXX_HAVE_ATANF 1
01281 # define atanf _atanf
01282 #endif
01283 
01284 #if defined (_GLIBCXX_HAVE__ATANL) && ! defined (_GLIBCXX_HAVE_ATANL)
01285 # define _GLIBCXX_HAVE_ATANL 1
01286 # define atanl _atanl
01287 #endif
01288 
01289 #if defined (_GLIBCXX_HAVE__CEILF) && ! defined (_GLIBCXX_HAVE_CEILF)
01290 # define _GLIBCXX_HAVE_CEILF 1
01291 # define ceilf _ceilf
01292 #endif
01293 
01294 #if defined (_GLIBCXX_HAVE__CEILL) && ! defined (_GLIBCXX_HAVE_CEILL)
01295 # define _GLIBCXX_HAVE_CEILL 1
01296 # define ceill _ceill
01297 #endif
01298 
01299 #if defined (_GLIBCXX_HAVE__COSF) && ! defined (_GLIBCXX_HAVE_COSF)
01300 # define _GLIBCXX_HAVE_COSF 1
01301 # define cosf _cosf
01302 #endif
01303 
01304 #if defined (_GLIBCXX_HAVE__COSHF) && ! defined (_GLIBCXX_HAVE_COSHF)
01305 # define _GLIBCXX_HAVE_COSHF 1
01306 # define coshf _coshf
01307 #endif
01308 
01309 #if defined (_GLIBCXX_HAVE__COSHL) && ! defined (_GLIBCXX_HAVE_COSHL)
01310 # define _GLIBCXX_HAVE_COSHL 1
01311 # define coshl _coshl
01312 #endif
01313 
01314 #if defined (_GLIBCXX_HAVE__COSL) && ! defined (_GLIBCXX_HAVE_COSL)
01315 # define _GLIBCXX_HAVE_COSL 1
01316 # define cosl _cosl
01317 #endif
01318 
01319 #if defined (_GLIBCXX_HAVE__EXPF) && ! defined (_GLIBCXX_HAVE_EXPF)
01320 # define _GLIBCXX_HAVE_EXPF 1
01321 # define expf _expf
01322 #endif
01323 
01324 #if defined (_GLIBCXX_HAVE__EXPL) && ! defined (_GLIBCXX_HAVE_EXPL)
01325 # define _GLIBCXX_HAVE_EXPL 1
01326 # define expl _expl
01327 #endif
01328 
01329 #if defined (_GLIBCXX_HAVE__FABSF) && ! defined (_GLIBCXX_HAVE_FABSF)
01330 # define _GLIBCXX_HAVE_FABSF 1
01331 # define fabsf _fabsf
01332 #endif
01333 
01334 #if defined (_GLIBCXX_HAVE__FABSL) && ! defined (_GLIBCXX_HAVE_FABSL)
01335 # define _GLIBCXX_HAVE_FABSL 1
01336 # define fabsl _fabsl
01337 #endif
01338 
01339 #if defined (_GLIBCXX_HAVE__FINITE) && ! defined (_GLIBCXX_HAVE_FINITE)
01340 # define _GLIBCXX_HAVE_FINITE 1
01341 # define finite _finite
01342 #endif
01343 
01344 #if defined (_GLIBCXX_HAVE__FINITEF) && ! defined (_GLIBCXX_HAVE_FINITEF)
01345 # define _GLIBCXX_HAVE_FINITEF 1
01346 # define finitef _finitef
01347 #endif
01348 
01349 #if defined (_GLIBCXX_HAVE__FINITEL) && ! defined (_GLIBCXX_HAVE_FINITEL)
01350 # define _GLIBCXX_HAVE_FINITEL 1
01351 # define finitel _finitel
01352 #endif
01353 
01354 #if defined (_GLIBCXX_HAVE__FLOORF) && ! defined (_GLIBCXX_HAVE_FLOORF)
01355 # define _GLIBCXX_HAVE_FLOORF 1
01356 # define floorf _floorf
01357 #endif
01358 
01359 #if defined (_GLIBCXX_HAVE__FLOORL) && ! defined (_GLIBCXX_HAVE_FLOORL)
01360 # define _GLIBCXX_HAVE_FLOORL 1
01361 # define floorl _floorl
01362 #endif
01363 
01364 #if defined (_GLIBCXX_HAVE__FMODF) && ! defined (_GLIBCXX_HAVE_FMODF)
01365 # define _GLIBCXX_HAVE_FMODF 1
01366 # define fmodf _fmodf
01367 #endif
01368 
01369 #if defined (_GLIBCXX_HAVE__FMODL) && ! defined (_GLIBCXX_HAVE_FMODL)
01370 # define _GLIBCXX_HAVE_FMODL 1
01371 # define fmodl _fmodl
01372 #endif
01373 
01374 #if defined (_GLIBCXX_HAVE__FPCLASS) && ! defined (_GLIBCXX_HAVE_FPCLASS)
01375 # define _GLIBCXX_HAVE_FPCLASS 1
01376 # define fpclass _fpclass
01377 #endif
01378 
01379 #if defined (_GLIBCXX_HAVE__FREXPF) && ! defined (_GLIBCXX_HAVE_FREXPF)
01380 # define _GLIBCXX_HAVE_FREXPF 1
01381 # define frexpf _frexpf
01382 #endif
01383 
01384 #if defined (_GLIBCXX_HAVE__FREXPL) && ! defined (_GLIBCXX_HAVE_FREXPL)
01385 # define _GLIBCXX_HAVE_FREXPL 1
01386 # define frexpl _frexpl
01387 #endif
01388 
01389 #if defined (_GLIBCXX_HAVE__HYPOT) && ! defined (_GLIBCXX_HAVE_HYPOT)
01390 # define _GLIBCXX_HAVE_HYPOT 1
01391 # define hypot _hypot
01392 #endif
01393 
01394 #if defined (_GLIBCXX_HAVE__HYPOTF) && ! defined (_GLIBCXX_HAVE_HYPOTF)
01395 # define _GLIBCXX_HAVE_HYPOTF 1
01396 # define hypotf _hypotf
01397 #endif
01398 
01399 #if defined (_GLIBCXX_HAVE__HYPOTL) && ! defined (_GLIBCXX_HAVE_HYPOTL)
01400 # define _GLIBCXX_HAVE_HYPOTL 1
01401 # define hypotl _hypotl
01402 #endif
01403 
01404 #if defined (_GLIBCXX_HAVE__ISINF) && ! defined (_GLIBCXX_HAVE_ISINF)
01405 # define _GLIBCXX_HAVE_ISINF 1
01406 # define isinf _isinf
01407 #endif
01408 
01409 #if defined (_GLIBCXX_HAVE__ISINFF) && ! defined (_GLIBCXX_HAVE_ISINFF)
01410 # define _GLIBCXX_HAVE_ISINFF 1
01411 # define isinff _isinff
01412 #endif
01413 
01414 #if defined (_GLIBCXX_HAVE__ISINFL) && ! defined (_GLIBCXX_HAVE_ISINFL)
01415 # define _GLIBCXX_HAVE_ISINFL 1
01416 # define isinfl _isinfl
01417 #endif
01418 
01419 #if defined (_GLIBCXX_HAVE__ISNAN) && ! defined (_GLIBCXX_HAVE_ISNAN)
01420 # define _GLIBCXX_HAVE_ISNAN 1
01421 # define isnan _isnan
01422 #endif
01423 
01424 #if defined (_GLIBCXX_HAVE__ISNANF) && ! defined (_GLIBCXX_HAVE_ISNANF)
01425 # define _GLIBCXX_HAVE_ISNANF 1
01426 # define isnanf _isnanf
01427 #endif
01428 
01429 #if defined (_GLIBCXX_HAVE__ISNANL) && ! defined (_GLIBCXX_HAVE_ISNANL)
01430 # define _GLIBCXX_HAVE_ISNANL 1
01431 # define isnanl _isnanl
01432 #endif
01433 
01434 #if defined (_GLIBCXX_HAVE__LDEXPF) && ! defined (_GLIBCXX_HAVE_LDEXPF)
01435 # define _GLIBCXX_HAVE_LDEXPF 1
01436 # define ldexpf _ldexpf
01437 #endif
01438 
01439 #if defined (_GLIBCXX_HAVE__LDEXPL) && ! defined (_GLIBCXX_HAVE_LDEXPL)
01440 # define _GLIBCXX_HAVE_LDEXPL 1
01441 # define ldexpl _ldexpl
01442 #endif
01443 
01444 #if defined (_GLIBCXX_HAVE__LOG10F) && ! defined (_GLIBCXX_HAVE_LOG10F)
01445 # define _GLIBCXX_HAVE_LOG10F 1
01446 # define log10f _log10f
01447 #endif
01448 
01449 #if defined (_GLIBCXX_HAVE__LOG10L) && ! defined (_GLIBCXX_HAVE_LOG10L)
01450 # define _GLIBCXX_HAVE_LOG10L 1
01451 # define log10l _log10l
01452 #endif
01453 
01454 #if defined (_GLIBCXX_HAVE__LOGF) && ! defined (_GLIBCXX_HAVE_LOGF)
01455 # define _GLIBCXX_HAVE_LOGF 1
01456 # define logf _logf
01457 #endif
01458 
01459 #if defined (_GLIBCXX_HAVE__LOGL) && ! defined (_GLIBCXX_HAVE_LOGL)
01460 # define _GLIBCXX_HAVE_LOGL 1
01461 # define logl _logl
01462 #endif
01463 
01464 #if defined (_GLIBCXX_HAVE__MODF) && ! defined (_GLIBCXX_HAVE_MODF)
01465 # define _GLIBCXX_HAVE_MODF 1
01466 # define modf _modf
01467 #endif
01468 
01469 #if defined (_GLIBCXX_HAVE__MODFF) && ! defined (_GLIBCXX_HAVE_MODFF)
01470 # define _GLIBCXX_HAVE_MODFF 1
01471 # define modff _modff
01472 #endif
01473 
01474 #if defined (_GLIBCXX_HAVE__MODFL) && ! defined (_GLIBCXX_HAVE_MODFL)
01475 # define _GLIBCXX_HAVE_MODFL 1
01476 # define modfl _modfl
01477 #endif
01478 
01479 #if defined (_GLIBCXX_HAVE__POWF) && ! defined (_GLIBCXX_HAVE_POWF)
01480 # define _GLIBCXX_HAVE_POWF 1
01481 # define powf _powf
01482 #endif
01483 
01484 #if defined (_GLIBCXX_HAVE__POWL) && ! defined (_GLIBCXX_HAVE_POWL)
01485 # define _GLIBCXX_HAVE_POWL 1
01486 # define powl _powl
01487 #endif
01488 
01489 #if defined (_GLIBCXX_HAVE__QFPCLASS) && ! defined (_GLIBCXX_HAVE_QFPCLASS)
01490 # define _GLIBCXX_HAVE_QFPCLASS 1
01491 # define qfpclass _qfpclass
01492 #endif
01493 
01494 #if defined (_GLIBCXX_HAVE__SINCOS) && ! defined (_GLIBCXX_HAVE_SINCOS)
01495 # define _GLIBCXX_HAVE_SINCOS 1
01496 # define sincos _sincos
01497 #endif
01498 
01499 #if defined (_GLIBCXX_HAVE__SINCOSF) && ! defined (_GLIBCXX_HAVE_SINCOSF)
01500 # define _GLIBCXX_HAVE_SINCOSF 1
01501 # define sincosf _sincosf
01502 #endif
01503 
01504 #if defined (_GLIBCXX_HAVE__SINCOSL) && ! defined (_GLIBCXX_HAVE_SINCOSL)
01505 # define _GLIBCXX_HAVE_SINCOSL 1
01506 # define sincosl _sincosl
01507 #endif
01508 
01509 #if defined (_GLIBCXX_HAVE__SINF) && ! defined (_GLIBCXX_HAVE_SINF)
01510 # define _GLIBCXX_HAVE_SINF 1
01511 # define sinf _sinf
01512 #endif
01513 
01514 #if defined (_GLIBCXX_HAVE__SINHF) && ! defined (_GLIBCXX_HAVE_SINHF)
01515 # define _GLIBCXX_HAVE_SINHF 1
01516 # define sinhf _sinhf
01517 #endif
01518 
01519 #if defined (_GLIBCXX_HAVE__SINHL) && ! defined (_GLIBCXX_HAVE_SINHL)
01520 # define _GLIBCXX_HAVE_SINHL 1
01521 # define sinhl _sinhl
01522 #endif
01523 
01524 #if defined (_GLIBCXX_HAVE__SINL) && ! defined (_GLIBCXX_HAVE_SINL)
01525 # define _GLIBCXX_HAVE_SINL 1
01526 # define sinl _sinl
01527 #endif
01528 
01529 #if defined (_GLIBCXX_HAVE__SQRTF) && ! defined (_GLIBCXX_HAVE_SQRTF)
01530 # define _GLIBCXX_HAVE_SQRTF 1
01531 # define sqrtf _sqrtf
01532 #endif
01533 
01534 #if defined (_GLIBCXX_HAVE__SQRTL) && ! defined (_GLIBCXX_HAVE_SQRTL)
01535 # define _GLIBCXX_HAVE_SQRTL 1
01536 # define sqrtl _sqrtl
01537 #endif
01538 
01539 #if defined (_GLIBCXX_HAVE__STRTOF) && ! defined (_GLIBCXX_HAVE_STRTOF)
01540 # define _GLIBCXX_HAVE_STRTOF 1
01541 # define strtof _strtof
01542 #endif
01543 
01544 #if defined (_GLIBCXX_HAVE__STRTOLD) && ! defined (_GLIBCXX_HAVE_STRTOLD)
01545 # define _GLIBCXX_HAVE_STRTOLD 1
01546 # define strtold _strtold
01547 #endif
01548 
01549 #if defined (_GLIBCXX_HAVE__TANF) && ! defined (_GLIBCXX_HAVE_TANF)
01550 # define _GLIBCXX_HAVE_TANF 1
01551 # define tanf _tanf
01552 #endif
01553 
01554 #if defined (_GLIBCXX_HAVE__TANHF) && ! defined (_GLIBCXX_HAVE_TANHF)
01555 # define _GLIBCXX_HAVE_TANHF 1
01556 # define tanhf _tanhf
01557 #endif
01558 
01559 #if defined (_GLIBCXX_HAVE__TANHL) && ! defined (_GLIBCXX_HAVE_TANHL)
01560 # define _GLIBCXX_HAVE_TANHL 1
01561 # define tanhl _tanhl
01562 #endif
01563 
01564 #if defined (_GLIBCXX_HAVE__TANL) && ! defined (_GLIBCXX_HAVE_TANL)
01565 # define _GLIBCXX_HAVE_TANL 1
01566 # define tanl _tanl
01567 #endif
01568 
01569 #endif // _GLIBCXX_CXX_CONFIG_H
