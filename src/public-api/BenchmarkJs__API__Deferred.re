module Impl = (T: {
                 type t;
                 type benchmark;
               }) => {
  module Internal =
    BenchmarkJs__FFI.Deferred.Impl({
      type t = T.t;
      type benchmark = T.benchmark;
    });
  let getBenchmark: T.t => T.benchmark = Internal.getBenchmark;
  let getCycle: T.t => float = Internal.getCycle;
  let getElapsed: T.t => float = Internal.getElapsed;
  let getTimeStamp: T.t => float = Internal.getTimeStamp;
};

type t = BenchmarkJs__Types.deferred;

include Impl({
  type nonrec t = t;
  type benchmark = BenchmarkJs__Types.benchmark;
});