module Impl = (T: {type benchmark;}) => {
  [@bs.module "benchmark"] [@bs.scope "Benchmark"] external formatNumber: float => string = "formatNumber";
  [@bs.module "benchmark"] [@bs.scope "Benchmark"]
  /** [ filterBenchmarks(benchmarkArray, predicate) ]:
   *  Filters an array of benchmark objects based on
   *  the return value of the predicate function.
   */
  external filterBenchmarks: (array(T.benchmark), T.benchmark => bool) => array(T.benchmark) = "filter";
  [@bs.module "benchmark"] [@bs.scope "Benchmark"]
  external filterByFastest: (array(T.benchmark), [@bs.as "fastest"] _) => array(T.benchmark) = "filter";
  [@bs.module "benchmark"] [@bs.scope "Benchmark"]
  external filterBySlowest: (array(T.benchmark), [@bs.as "slowest"] _) => array(T.benchmark) = "filter";
  [@bs.module "benchmark"] [@bs.scope "Benchmark"]
  external filterBySuccessful: (array(T.benchmark), [@bs.as "successful"] _) => array(T.benchmark) = "filter";
};

include Impl({
  type benchmark = BenchmarkJs__Types.benchmark;
});