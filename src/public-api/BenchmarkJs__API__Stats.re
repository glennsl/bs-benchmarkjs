
module Impl = (T: {
  type t;
}) => {
  /** [module Internal] For internal use, not recommended for public use. */
  module Internal = {
    include BenchmarkJs__FFI.Stats.Impl({
      type t = T.t;
    });
  };
  let getDeviation: T.t => float = Internal.getDeviation;
  let getMean: T.t => float = Internal.getMean;
  let getMOE: T.t => float = Internal.getMOE;
  let getRME: T.t => float = Internal.getRME;
  let getSample: T.t => array(float) = Internal.getSample;
  let getSEM: T.t => float = Internal.getSEM;
  let getVariance: T.t => float = Internal.getVariance;
}

type t = BenchmarkJs__Types.stats;

include Impl({ type nonrec t = t; });
