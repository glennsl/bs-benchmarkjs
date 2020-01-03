module Impl = (T: {
  type t;
}) => {
  module Internal = {
    include Glennsl__BsBenchmarkJs__FFI.Stats.Impl({
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
};