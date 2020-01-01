
module Impl = (T: {
  type t;
  type eventHandler;
  type testFn;
  type setupFn;
  type teardownFn;
}) => {
  [@bs.set] external setAsync: (T.t, bool) => unit = "async";
  [@bs.set] external setDefer: (T.t, bool) => unit = "defer";
  [@bs.set] external setDelay: (T.t, float) => unit = "delay";
  [@bs.set] external setId: (T.t, string) => unit = "id";
  [@bs.set] external setInitCount: (T.t, int) => unit = "initCount";
  [@bs.set] external setMaxTime: (T.t, float) => unit = "maxTime";
  [@bs.set] external setMinSamples: (T.t, int) => unit = "minSamples";
  [@bs.set] external setMinTime: (T.t, float) => unit = "minTime";
  [@bs.set] external setName: (T.t, string) => unit = "name";
  [@bs.set] external setOnAbort: (T.t, T.eventHandler) => unit = "onAbort";
  [@bs.set] external setOnComplete: (T.t, T.eventHandler) => unit = "onComplete";
  [@bs.set] external setOnCycle: (T.t, T.eventHandler) => unit = "onCycle";
  [@bs.set] external setOnError: (T.t, T.eventHandler) => unit = "onError";
  [@bs.set] external setOnReset: (T.t, T.eventHandler) => unit = "onReset";
  [@bs.set] external setOnStart: (T.t, T.eventHandler) => unit = "onStart";
  [@bs.set] external setFn: (T.t, T.testFn) => unit = "fn";
  [@bs.set] external setSetup: (T.t, T.setupFn) => unit = "setup";
  [@bs.set] external setTeardown: (T.t, T.teardownFn) => unit = "teardown";
  [@bs.set] external setQueued: (T.t, bool) => unit = "queued";

  [@bs.get] external getAsync: T.t => Js.Nullable.t(bool) = "async";
  [@bs.get] external getDefer: T.t => Js.Nullable.t(bool) = "defer";
  [@bs.get] external getDelay: T.t => Js.Nullable.t(float) = "delay";
  [@bs.get] external getId: T.t => Js.Nullable.t(string) = "id";
  [@bs.get] external getInitCount: T.t => Js.Nullable.t(int) = "initCount";
  [@bs.get] external getMaxTime: T.t => Js.Nullable.t(float) = "maxTime";
  [@bs.get] external getMinSamples: T.t => Js.Nullable.t(int) = "minSamples";
  [@bs.get] external getMinTime: T.t => Js.Nullable.t(float) = "minTime";
  [@bs.get] external getName: T.t => Js.Nullable.t(string) = "name";
  [@bs.get] external getOnAbort: T.t => Js.Nullable.t(T.eventHandler) = "onAbort";
  [@bs.get] external getOnComplete: T.t => Js.Nullable.t(T.eventHandler) = "onComplete";
  [@bs.get] external getOnCycle: T.t => Js.Nullable.t(T.eventHandler) = "onCycle";
  [@bs.get] external getOnError: T.t => Js.Nullable.t(T.eventHandler) = "onError";
  [@bs.get] external getOnReset: T.t => Js.Nullable.t(T.eventHandler) = "onReset";
  [@bs.get] external getOnStart: T.t => Js.Nullable.t(T.eventHandler) = "onStart";
  [@bs.get] external getFn: T.t => Js.Nullable.t(T.testFn) = "fn";
  [@bs.get] external getSetup: T.t => Js.Nullable.t(T.setupFn) = "setup";
  [@bs.get] external getTeardown: T.t => Js.Nullable.t(T.teardownFn) = "teardown";
  [@bs.get] external getQueued: T.t => Js.Nullable.t(bool) = "queued";
};