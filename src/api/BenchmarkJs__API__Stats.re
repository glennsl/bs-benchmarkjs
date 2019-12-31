module Impl = (T: {
  type t;
}) => {
  module Internal = {
    include BenchmarkJs__FFI.Stats.Impl({
      type t = T.t;
    });
  };
  /** Returns the standard deviation of the sample. */
  let getDeviation: T.t => float = Internal.getDeviation;
  /** Returns the mean of the sample. */
  let getMean: T.t => float = Internal.getMean;
  /** Returns the margin of error of the sample. */
  let getMOE: T.t => float = Internal.getMOE;
  /** Returns the relative margin of error of the sample. */
  let getRME: T.t => float = Internal.getRME;
  /** Returns an array of sampled time periods. */
  let getSample: T.t => array(float) = Internal.getSample;
  /** Returns the standard error of the mean of the sample. */
  let getSEM: T.t => float = Internal.getSEM;
  /** Returns the variance of the sample. */
  let getVariance: T.t => float = Internal.getVariance;
};