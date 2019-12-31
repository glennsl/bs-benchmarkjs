
module Impl = (T: {
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
  let encodeEventType: eventType => string;
  let decodeEventType: string => eventType;
}) =>  {

  module Benchmark = BenchmarkJs__API__Benchmark.Impl({
    type t = T.benchmark;
    type options = T.options;
    type testFn = T.testFn;
    type setupFn = T.setupFn;
    type teardownFn = T.teardownFn;
    type stats = T.stats;
    type times = T.times;
  });

  module Deferred = BenchmarkJs__API__Deferred.Impl({
    type t = T.deferred;
    type benchmark = T.benchmark;
  });

  module Event = BenchmarkJs__API__Event.Impl({
    type t = T.event;
    type benchmark = T.benchmark;
    type eventType = T.eventType;
    let encodeEventType = T.encodeEventType;
    let decodeEventType = T.decodeEventType;
  });

  module Options = BenchmarkJs__API__Options.Impl({
    type t = T.options;
    type testFn = T.testFn;
    type setupFn = T.setupFn;
    type teardownFn = T.teardownFn;
    type eventHandler = T.eventHandler;
  });

  module Platform = BenchmarkJs__API__Platform;

  module Stats = BenchmarkJs__API__Stats.Impl({
    type t = T.stats;
  });

  module SuiteOptions = BenchmarkJs__API__SuiteOptions.Impl({
    type t = T.suiteOptions;
    type eventHandler = T.eventHandler;
  });

  module Suite = BenchmarkJs__API__Suite.Impl({
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
    let encodeEventType: eventType => string = T.encodeEventType;
    let decodeEventType: string => eventType = T.decodeEventType;
  });

  module Support = BenchmarkJs__API__Support;

  module Times = BenchmarkJs__API__Times.Impl({
    type t = T.times;
  });

  module Utils = BenchmarkJs__API__Utils.Impl({
    type benchmark = T.benchmark;
  });

};

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
type eventType = BenchmarkJs__Types.eventType;
type eventHandler;
type testFn;
type setupFn;
type teardownFn;
let encodeEventType = BenchmarkJs__Types.encodeEventType;
let decodeEventType = BenchmarkJs__Types.decodeEventType;

include Impl({
  type nonrec benchmark = benchmark;
  type nonrec suite = suite;
  type nonrec suiteOptions = suiteOptions;
  type nonrec deferred = deferred;
  type nonrec event = event;
  type nonrec options = options;
  type nonrec times = times;
  type nonrec stats = stats;
  type nonrec platform = platform;
  type nonrec support = support;
  type nonrec eventType = eventType;
  type nonrec eventHandler = eventHandler;
  type nonrec testFn = testFn;
  type nonrec setupFn = setupFn;
  type nonrec teardownFn = teardownFn;
  let encodeEventType = encodeEventType;
  let decodeEventType = decodeEventType;
});

