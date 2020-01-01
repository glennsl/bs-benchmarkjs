/**
 * [ Support ]
 *
 * An object used internally by Benchmark.js which is inspected
 * to determine the presence of certain runtime features. Those features
 * affect the way Benchmark.js handles certain things, like async
 * benchmarking, and function decompilation.
 *
 * Decompilation can be used to thwart runtime optimizations over
 * the course of sampling a test case, possibly improvint the reliability
 * of the results.
 */
module Impl = (T: {type t;}) => {
  module Internal =
    Glennsl__BsBenchmarkJs__FFI.Support.Impl({
      type t = T.t;
    });
  let browser: bool = Internal.(getBrowser(data));
  let decompilation: bool = Internal.(getDecompilation(data));
  let timeout: bool = Internal.(getTimeout(data));
};

include Impl({
  include Types;
  type t = support;
});