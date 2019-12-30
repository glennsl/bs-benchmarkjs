module Impl = (T: {
                 type t;
                 type benchmark;
               }) => {
  [@bs.get] external getBenchmark: T.t => T.benchmark = "benchmark";
  [@bs.get] external getCycle: T.t => float = "cycle";
  [@bs.get] external getElapsed: T.t => float = "elapsed";
  [@bs.get] external getTimeStamp: T.t => float = "timeStamp";
};

type t = BenchmarkJs__Types.deferred;

include Impl({
  type nonrec t = t;
  type benchmark = BenchmarkJs__Types.benchmark;
});