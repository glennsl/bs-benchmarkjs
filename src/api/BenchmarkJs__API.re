/**
 * All of the API submodules are implemented via functors to provide the
 * type definitions from the top level downward. This module functor acts
 * as a routing point for all type definitions to flow to those submodule
 * functors.
 */
module Impl =
       (
         T: {
           type benchmark;
           type suite;
           type suiteOptions;
           type deferred;
           type event;
           type options;
           type times;
           type stats;
           type platform;
           type support;
           type eventType;
           type eventHandler;
           type testFn;
           type setupFn;
           type teardownFn;
           let eventTypeToString: eventType => string;
           let eventTypeFromString: string => eventType;
         },
       ) => {
  module Benchmark =
    BenchmarkJs__API__Benchmark.Impl({
      type t = T.benchmark;
      type options = T.options;
      type testFn = T.testFn;
      type setupFn = T.setupFn;
      type teardownFn = T.teardownFn;
      type stats = T.stats;
      type times = T.times;
    });

  module Deferred =
    BenchmarkJs__API__Deferred.Impl({
      type t = T.deferred;
      type benchmark = T.benchmark;
    });

  module Event =
    BenchmarkJs__API__Event.Impl({
      type t = T.event;
      type benchmark = T.benchmark;
      type eventType = T.eventType;
      let eventTypeToString = T.eventTypeToString;
      let eventTypeFromString = T.eventTypeFromString;
    });

  module Options =
    BenchmarkJs__API__Options.Impl({
      type t = T.options;
      type testFn = T.testFn;
      type setupFn = T.setupFn;
      type teardownFn = T.teardownFn;
      type eventHandler = T.eventHandler;
    });

  module Platform = BenchmarkJs__API__Platform;

  module Stats =
    BenchmarkJs__API__Stats.Impl({
      type t = T.stats;
    });

  module SuiteOptions =
    BenchmarkJs__API__SuiteOptions.Impl({
      type t = T.suiteOptions;
      type eventHandler = T.eventHandler;
    });

  module Suite =
    BenchmarkJs__API__Suite.Impl({
      type t = T.suite;
      type benchmark = T.benchmark;
      type suiteOptions = T.suiteOptions;
      type options = T.options;
      type stats = T.stats;
      type times = T.times;
      type event = T.event;
      type eventHandler = T.eventHandler;
      type testFn = T.testFn;
      type setupFn = T.setupFn;
      type teardownFn = T.teardownFn;
      type eventType = T.eventType;
      let eventTypeToString: eventType => string = T.eventTypeToString;
      let eventTypeFromString: string => eventType = T.eventTypeFromString;
    });

  module Support = BenchmarkJs__API__Support;

  module Times =
    BenchmarkJs__API__Times.Impl({
      type t = T.times;
    });

  module Utils =
    BenchmarkJs__API__Utils.Impl({
      type benchmark = T.benchmark;
    });
};
