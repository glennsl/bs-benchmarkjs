module Impl = (T: {
                 type t;
                 type options;
                 type stats;
                 type times;
                 type testFn;
                 type setupFn;
                 type teardownFn;
               }) => {
  [@bs.module "benchmark"] [@bs.new] external make: (string, T.testFn, ~options: T.options=?) => T.t = "Benchmark";
  module MakeWith = {
    [@bs.module "benchmark"] [@bs.new] external fn: T.testFn => T.t = "Benchmark";
    [@bs.module "benchmark"] [@bs.new] external fn_options: (T.testFn, T.options) => T.t = "Benchmark";
    [@bs.module "benchmark"] [@bs.new] external options: T.options => T.t = "Benchmark";
    [@bs.module "benchmark"] [@bs.new] external name_fn: (string, T.testFn) => T.t = "Benchmark";
    [@bs.module "benchmark"] [@bs.new] external name_fn_options: (string, T.testFn, T.options) => T.t = "Benchmark";
    [@bs.module "benchmark"] [@bs.new] external name_options: (string, T.options) => T.t = "Benchmark";
  };
  // instance properties
  [@bs.get] external getAborted: T.t => bool = "aborted";
  [@bs.get] external getCompiled: T.t => T.testFn = "compiled";
  [@bs.get] external getCycles: T.t => int = "cycles";
  [@bs.get] external getCount: T.t => int = "count";
  [@bs.get] external getError: T.t => Js.Null_undefined.t(Js.Exn.t) = "error";
  [@bs.get] external getFn: T.t => T.testFn = "fn";
  [@bs.get] external getHz: T.t => float = "hz";
  [@bs.get] external getRunning: T.t => bool = "running";
  [@bs.get] external getSetup: T.t => T.setupFn = "setup";
  [@bs.get] external getStats: T.t => T.stats = "stats";
  [@bs.get] external getTeardown: T.t => T.teardownFn = "teardown";
  [@bs.get] external getTime: T.t => T.times = "time";
  [@bs.get] external getName: T.t => string = "name";
  [@bs.get] external getOptions: T.t => T.options = "options";
  // instance methods
  [@bs.send.pipe: T.t] external run: T.t = "run";
  [@bs.send.pipe: T.t] external runWithOptions: T.options => T.t = "run";
  [@bs.send.pipe: T.t] external abort: T.t = "abort";
  [@bs.send.pipe: T.t] external toString: string = "toString";
  [@bs.send.pipe: T.t] external clone: T.t => T.t = "clone";
  [@bs.send.pipe: T.t] external cloneWithOptions: (T.t, T.options) => T.t = "clone";
  [@bs.send.pipe: T.t] external cmp: T.t => int = "compare";
  [@bs.send.pipe: T.t] external reset: T.t = "reset";
};

type t = BenchmarkJs__Types.benchmark;

include Impl({
  type nonrec t = t;
  include BenchmarkJs__Types;
});