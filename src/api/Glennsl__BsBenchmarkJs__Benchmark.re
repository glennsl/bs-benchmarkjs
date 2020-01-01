
module Impl = (T: {
  type t;
  type options;
  type testFn;
  type setupFn;
  type teardownFn;
  type times;
  type stats;
}) => {
  module Internal = {
    include Glennsl__BsBenchmarkJs__FFI.Benchmark.Impl({
      type t = T.t;
      type options = T.options;
      type testFn = T.testFn;
      type setupFn = T.setupFn;
      type teardownFn = T.teardownFn;
      type times = T.times;
      type stats = T.stats;
    });
  };
  let getAborted: T.t => bool = Internal.getAborted;
  let getCompiled: T.t => T.testFn = Internal.getCompiled;
  let getCycles: T.t => int = Internal.getCycles;
  let getCount: T.t => int = Internal.getCount;
  let getError: T.t => Js.Null_undefined.t(Js.Exn.t) = Internal.getError;
  let getFn: T.t => T.testFn = Internal.getFn;
  let getHz: T.t => float = Internal.getHz;
  let getRunning: T.t => bool = Internal.getRunning;
  let getSetup: T.t => T.setupFn = Internal.getSetup;
  let getStats: T.t => T.stats = Internal.getStats;
  let getTeardown: T.t => T.teardownFn = Internal.getTeardown;
  let getTime: T.t => T.times = Internal.getTime;
  let getName: T.t => string = Internal.getName;
  let getOptions: T.t => T.options = Internal.getOptions;

  let make: (~name: string=?, ~options: T.options=?, T.testFn) => T.t =
    Internal.(
      (~name=?, ~options=?, fn) =>
        (name, options)
        |> (
          fun
          | (None, None) => MakeWith.fn(fn)
          | (Some(n), None) => MakeWith.name_fn(n, fn)
          | (None, Some(opt)) => MakeWith.fn_options(fn, opt)
          | (Some(n), Some(opt)) => MakeWith.name_fn_options(n, fn, opt)
        )
    );

  let run: (~options: T.options=?, T.t) => T.t =
    Internal.(
      (~options=?, benchmark) =>
        options
        |> (
          fun
          | None => run(benchmark)
          | Some(opt) => runWithOptions(opt, benchmark)
        )
    );
};

include Impl({
  include Types;
  type t = benchmark;
});