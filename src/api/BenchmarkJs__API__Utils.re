module Impl = (T: {
                 type benchmark;
               }) => {
  module Internal =
    BenchmarkJs__FFI.Utils.Impl({
      include T;
    });
  let formatFloat: float => string = Internal.formatNumber;
  let filterBenchmarks: (array(T.benchmark), T.benchmark => bool) => array(T.benchmark) = Internal.filterBenchmarks;
  let filterByFastest: array(T.benchmark) => array(T.benchmark) = Internal.filterByFastest;
  let filterBySlowest: array(T.benchmark) => array(T.benchmark) = Internal.filterBySlowest;
  let filterBySuccessful: array(T.benchmark) => array(T.benchmark) = Internal.filterBySuccessful;
};