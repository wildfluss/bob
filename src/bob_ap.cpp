/* -*- mode:C++; c-basic-offset: 2; -*- */

#include <Rcpp.h>
using namespace Rcpp;

// #include <bob.blitz/cppapi.h>
// #include <bob.blitz/cleanup.h>
// #include <bob.extension/defines.h>
#include <bob.ap/FrameExtractor.h>
#include <bob.ap/Energy.h>
#include <bob.ap/Spectrogram.h>
#include <bob.ap/Ceps.h>

// This is a simple example of exporting a C++ function to R. You can
// source this function into an R session using the Rcpp::sourceCpp
// function (or via the Source button on the editor toolbar). Learn
// more about Rcpp at:
//
//   http://www.rcpp.org/
//   http://adv-r.had.co.nz/Rcpp.html
//   http://gallery.rcpp.org/
//

// [[Rcpp::export]]
NumericVector timesTwo(NumericVector x) {
  return x * 2;
}

// https://www.idiap.ch/software/bob/docs/releases/last/doxygen/html/classbob_1_1ap_1_1Ceps.html#details

// [[Rcpp::export]]
double ceps(double rate, double win_length_ms = 20, double win_shift_ms = 10
          , double n_filters = 24, double n_ceps = 19, double f_min = 0.
          , double f_max = 4000., double delta_win = 2
          , double pre_emphasis_coeff = 1.0, bool mel_scale = true
          , bool dct_norm = true)
{
  Rcout << "rate: " << rate << "\n";
  Rcout << "win_length_ms: " << win_length_ms << "\n";
  Rcout << "win_shift_ms: " << win_shift_ms << "\n";
  Rcout << "n_filters: " << n_filters << "\n";
  Rcout << "n_ceps: " << n_ceps << "\n";
  Rcout << "f_min: " << f_min << "\n";
  Rcout << "f_max: " << f_max << "\n";
  Rcout << "delta_win: " << delta_win << "\n";
  Rcout << "pre_emphasis_coeff: " << pre_emphasis_coeff << "\n";
  Rcout << "mel_scale: " << mel_scale << "\n";
  Rcout << "dct_norm: " << dct_norm << "\n";

  new bob::ap::Ceps(rate,
        win_length_ms, win_shift_ms, n_filters, n_ceps, f_min, f_max,
        delta_win, pre_emphasis_coeff, mel_scale, dct_norm);
  
  return 42;
}  

// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically
// run after the compilation.
//

/*** R
timesTwo(42)
*/
