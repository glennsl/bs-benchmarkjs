module Impl = (T: {type t;}) => {
  [@bs.get] external getDeviation: T.t => float = "deviation";
  [@bs.get] external getMean: T.t => float = "mean";
  [@bs.get] external getMOE: T.t => float = "moe";
  [@bs.get] external getRME: T.t => float = "rme";
  [@bs.get] external getSample: T.t => array(float) = "sample";
  [@bs.get] external getSEM: T.t => float = "sem";
  [@bs.get] external getVariance: T.t => float = "variance";
};

type t = BenchmarkJs__Types.stats;

include Impl({
  type nonrec t = t;
});