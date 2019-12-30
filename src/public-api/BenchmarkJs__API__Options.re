module type Intf = {
  open BenchmarkJs__Types;

  // type t = options;
  let copy: options => options;
  let empty: unit => options;

  let make:
    (
      ~async: bool=?,
      ~defer: bool=?,
      ~delay: float=?,
      ~id: string=?,
      ~initCount: int=?,
      ~maxTime: float=?,
      ~minSamples: int=?,
      ~minTime: float=?,
      ~name: string=?,
      ~onAbort: eventHandler=?,
      ~onComplete: eventHandler=?,
      ~onCycle: eventHandler=?,
      ~onError: eventHandler=?,
      ~onReset: eventHandler=?,
      ~onStart: eventHandler=?,
      ~fn: testFn=?,
      ~setup: setupFn=?,
      ~teardown: teardownFn=?,
      ~queued: bool=?,
      unit
    ) =>
    options;

  let update:
    (
      ~async: bool=?,
      ~defer: bool=?,
      ~delay: float=?,
      ~id: string=?,
      ~initCount: int=?,
      ~maxTime: float=?,
      ~minSamples: int=?,
      ~minTime: float=?,
      ~name: string=?,
      ~onAbort: eventHandler=?,
      ~onComplete: eventHandler=?,
      ~onCycle: eventHandler=?,
      ~onError: eventHandler=?,
      ~onReset: eventHandler=?,
      ~onStart: eventHandler=?,
      ~fn: testFn=?,
      ~setup: setupFn=?,
      ~teardown: teardownFn=?,
      ~queued: bool=?,
      options
    ) =>
    options;

  let getAsync: options => option(bool);
  let getDefer: options => option(bool);
  let getDelay: options => option(float);
  let getId: options => option(string);
  let getInitCount: options => option(int);
  let getMaxTime: options => option(float);
  let getMinSamples: options => option(int);
  let getMinTime: options => option(float);
  let getName: options => option(string);
  let getOnAbort: options => option(eventHandler);
  let getOnComplete: options => option(eventHandler);
  let getOnCycle: options => option(eventHandler);
  let getOnError: options => option(eventHandler);
  let getOnReset: options => option(eventHandler);
  let getOnStart: options => option(eventHandler);
  let getFn: options => option(testFn);
  let getSetup: options => option(setupFn);
  let getTeardown: options => option(teardownFn);
  let getQueued: options => option(bool);

  let setAsync: (bool, options) => options;
  let setDefer: (bool, options) => options;
  let setDelay: (float, options) => options;
  let setId: (string, options) => options;
  let setInitCount: (int, options) => options;
  let setMaxTime: (float, options) => options;
  let setMinSamples: (int, options) => options;
  let setMinTime: (float, options) => options;
  let setName: (string, options) => options;
  let setOnAbort: (eventHandler, options) => options;
  let setOnComplete: (eventHandler, options) => options;
  let setOnCycle: (eventHandler, options) => options;
  let setOnError: (eventHandler, options) => options;
  let setOnReset: (eventHandler, options) => options;
  let setOnStart: (eventHandler, options) => options;
  let setFn: (testFn, options) => options;
  let setSetup: (setupFn, options) => options;
  let setTeardown: (teardownFn, options) => options;
  let setQueued: (bool, options) => options;
};

module Impl = (T: {
  type t;
  type eventHandler;
  type testFn;
  type setupFn;
  type teardownFn;
}) => {

  module Internal = {
    include BenchmarkJs__FFI.Options.Impl({
      type t = T.t;
      type eventHandler = T.eventHandler;
      type testFn = T.testFn;
      type setupFn = T.setupFn;
      type teardownFn = T.teardownFn;
    });
    let nullToOption = Js.Null_undefined.toOption;
  };


  let copy: T.t => T.t = options => Js__Utils.Obj.shallowCopy(. options);
  let empty: unit => T.t = () => Js__Utils.Obj.empty(.);

  let make =
      (
        ~async: option(bool)=?,
        ~defer: option(bool)=?,
        ~delay: option(float)=?,
        ~id: option(string)=?,
        ~initCount: option(int)=?,
        ~maxTime: option(float)=?,
        ~minSamples: option(int)=?,
        ~minTime: option(float)=?,
        ~name: option(string)=?,
        ~onAbort: option(T.eventHandler)=?,
        ~onComplete: option(T.eventHandler)=?,
        ~onCycle: option(T.eventHandler)=?,
        ~onError: option(T.eventHandler)=?,
        ~onReset: option(T.eventHandler)=?,
        ~onStart: option(T.eventHandler)=?,
        ~fn: option(T.testFn)=?,
        ~setup: option(T.setupFn)=?,
        ~teardown: option(T.teardownFn)=?,
        ~queued: option(bool)=?,
        (),
      ) => {
    let opt: T.t = empty();
    let () =
      Internal.(
        {
          switch (async) {
          | None => ()
          | Some(x) => setAsync(opt, x)
          };
          switch (defer) {
          | None => ()
          | Some(x) => setDefer(opt, x)
          };
          switch (delay) {
          | None => ()
          | Some(x) => setDelay(opt, x)
          };
          switch (id) {
          | None => ()
          | Some(x) => setId(opt, x)
          };
          switch (initCount) {
          | None => ()
          | Some(x) => setInitCount(opt, x)
          };
          switch (maxTime) {
          | None => ()
          | Some(x) => setMaxTime(opt, x)
          };
          switch (minSamples) {
          | None => ()
          | Some(x) => setMinSamples(opt, x)
          };
          switch (minTime) {
          | None => ()
          | Some(x) => setMinTime(opt, x)
          };
          switch (name) {
          | None => ()
          | Some(x) => setName(opt, x)
          };
          switch (onAbort) {
          | None => ()
          | Some(x) => setOnAbort(opt, x)
          };
          switch (onComplete) {
          | None => ()
          | Some(x) => setOnComplete(opt, x)
          };
          switch (onCycle) {
          | None => ()
          | Some(x) => setOnCycle(opt, x)
          };
          switch (onError) {
          | None => ()
          | Some(x) => setOnError(opt, x)
          };
          switch (onReset) {
          | None => ()
          | Some(x) => setOnReset(opt, x)
          };
          switch (onStart) {
          | None => ()
          | Some(x) => setOnStart(opt, x)
          };
          switch (fn) {
          | None => ()
          | Some(x) => setFn(opt, x)
          };
          switch (setup) {
          | None => ()
          | Some(x) => setSetup(opt, x)
          };
          switch (teardown) {
          | None => ()
          | Some(x) => setTeardown(opt, x)
          };
          switch (queued) {
          | None => ()
          | Some(x) => setQueued(opt, x)
          };
        }
      );
    opt;
  };

  let update =
      (
        ~async: option(bool)=?,
        ~defer: option(bool)=?,
        ~delay: option(float)=?,
        ~id: option(string)=?,
        ~initCount: option(int)=?,
        ~maxTime: option(float)=?,
        ~minSamples: option(int)=?,
        ~minTime: option(float)=?,
        ~name: option(string)=?,
        ~onAbort: option(T.eventHandler)=?,
        ~onComplete: option(T.eventHandler)=?,
        ~onCycle: option(T.eventHandler)=?,
        ~onError: option(T.eventHandler)=?,
        ~onReset: option(T.eventHandler)=?,
        ~onStart: option(T.eventHandler)=?,
        ~fn: option(T.testFn)=?,
        ~setup: option(T.setupFn)=?,
        ~teardown: option(T.teardownFn)=?,
        ~queued: option(bool)=?,
        options: T.t,
      ) => {
    let opt: T.t = copy(options);
    let () =
      Internal.(
        {
          switch (async) {
          | None => ()
          | Some(x) => setAsync(opt, x)
          };
          switch (defer) {
          | None => ()
          | Some(x) => setDefer(opt, x)
          };
          switch (delay) {
          | None => ()
          | Some(x) => setDelay(opt, x)
          };
          switch (id) {
          | None => ()
          | Some(x) => setId(opt, x)
          };
          switch (initCount) {
          | None => ()
          | Some(x) => setInitCount(opt, x)
          };
          switch (maxTime) {
          | None => ()
          | Some(x) => setMaxTime(opt, x)
          };
          switch (minSamples) {
          | None => ()
          | Some(x) => setMinSamples(opt, x)
          };
          switch (minTime) {
          | None => ()
          | Some(x) => setMinTime(opt, x)
          };
          switch (name) {
          | None => ()
          | Some(x) => setName(opt, x)
          };
          switch (onAbort) {
          | None => ()
          | Some(x) => setOnAbort(opt, x)
          };
          switch (onComplete) {
          | None => ()
          | Some(x) => setOnComplete(opt, x)
          };
          switch (onCycle) {
          | None => ()
          | Some(x) => setOnCycle(opt, x)
          };
          switch (onError) {
          | None => ()
          | Some(x) => setOnError(opt, x)
          };
          switch (onReset) {
          | None => ()
          | Some(x) => setOnReset(opt, x)
          };
          switch (onStart) {
          | None => ()
          | Some(x) => setOnStart(opt, x)
          };
          switch (fn) {
          | None => ()
          | Some(x) => setFn(opt, x)
          };
          switch (setup) {
          | None => ()
          | Some(x) => setSetup(opt, x)
          };
          switch (teardown) {
          | None => ()
          | Some(x) => setTeardown(opt, x)
          };
          switch (queued) {
          | None => ()
          | Some(x) => setQueued(opt, x)
          };
        }
      );
    opt;
  };

  let getAsync: T.t => option(bool) = Internal.(options => getAsync(options)->nullToOption);
  let getDefer: T.t => option(bool) = Internal.(options => getDefer(options)->nullToOption);
  let getDelay: T.t => option(float) = Internal.(options => getDelay(options)->nullToOption);
  let getId: T.t => option(string) = Internal.(options => getId(options)->nullToOption);
  let getInitCount: T.t => option(int) = Internal.(options => getInitCount(options)->nullToOption);
  let getMaxTime: T.t => option(float) = Internal.(options => getMaxTime(options)->nullToOption);
  let getMinSamples: T.t => option(int) = Internal.(options => getMinSamples(options)->nullToOption);
  let getMinTime: T.t => option(float) = Internal.(options => getMinTime(options)->nullToOption);
  let getName: T.t => option(string) = Internal.(options => getName(options)->nullToOption);
  let getOnAbort: T.t => option(T.eventHandler) = Internal.(options => getOnAbort(options)->nullToOption);
  let getOnComplete: T.t => option(T.eventHandler) = Internal.(options => getOnComplete(options)->nullToOption);
  let getOnCycle: T.t => option(T.eventHandler) = Internal.(options => getOnCycle(options)->nullToOption);
  let getOnError: T.t => option(T.eventHandler) = Internal.(options => getOnError(options)->nullToOption);
  let getOnReset: T.t => option(T.eventHandler) = Internal.(options => getOnReset(options)->nullToOption);
  let getOnStart: T.t => option(T.eventHandler) = Internal.(options => getOnStart(options)->nullToOption);
  let getFn: T.t => option(T.testFn) = Internal.(options => getFn(options)->nullToOption);
  let getSetup: T.t => option(T.setupFn) = Internal.(options => getSetup(options)->nullToOption);
  let getTeardown: T.t => option(T.teardownFn) = Internal.(options => getTeardown(options)->nullToOption);
  let getQueued: T.t => option(bool) = Internal.(options => getQueued(options)->nullToOption);

  let setAsync: (bool, T.t) => T.t =
    (async, opt) => {
      Internal.setAsync(opt, async);
      opt;
    };
  let setDefer: (bool, T.t) => T.t =
    (defer, opt) => {
      Internal.setDefer(opt, defer);
      opt;
    };
  let setDelay: (float, T.t) => T.t =
    (delay, opt) => {
      Internal.setDelay(opt, delay);
      opt;
    };
  let setId: (string, T.t) => T.t =
    (id, opt) => {
      Internal.setId(opt, id);
      opt;
    };
  let setInitCount: (int, T.t) => T.t =
    (initCount, opt) => {
      Internal.setInitCount(opt, initCount);
      opt;
    };
  let setMaxTime: (float, T.t) => T.t =
    (maxTime, opt) => {
      Internal.setMaxTime(opt, maxTime);
      opt;
    };
  let setMinSamples: (int, T.t) => T.t =
    (minSamples, opt) => {
      Internal.setMinSamples(opt, minSamples);
      opt;
    };
  let setMinTime: (float, T.t) => T.t =
    (minTime, opt) => {
      Internal.setMinTime(opt, minTime);
      opt;
    };
  let setName: (string, T.t) => T.t =
    (name, opt) => {
      Internal.setName(opt, name);
      opt;
    };
  let setOnAbort: (T.eventHandler, T.t) => T.t =
    (onAbort, opt) => {
      Internal.setOnAbort(opt, onAbort);
      opt;
    };
  let setOnComplete: (T.eventHandler, T.t) => T.t =
    (onComplete, opt) => {
      Internal.setOnComplete(opt, onComplete);
      opt;
    };
  let setOnCycle: (T.eventHandler, T.t) => T.t =
    (onCycle, opt) => {
      Internal.setOnCycle(opt, onCycle);
      opt;
    };
  let setOnError: (T.eventHandler, T.t) => T.t =
    (onError, opt) => {
      Internal.setOnError(opt, onError);
      opt;
    };
  let setOnReset: (T.eventHandler, T.t) => T.t =
    (onReset, opt) => {
      Internal.setOnReset(opt, onReset);
      opt;
    };
  let setOnStart: (T.eventHandler, T.t) => T.t =
    (onStart, opt) => {
      Internal.setOnStart(opt, onStart);
      opt;
    };
  let setFn: (T.testFn, T.t) => T.t =
    (fn, opt) => {
      Internal.setFn(opt, fn);
      opt;
    };
  let setSetup: (T.setupFn, T.t) => T.t =
    (setup, opt) => {
      Internal.setSetup(opt, setup);
      opt;
    };
  let setTeardown: (T.teardownFn, T.t) => T.t =
    (teardown, opt) => {
      Internal.setTeardown(opt, teardown);
      opt;
    };
  let setQueued: (bool, T.t) => T.t =
    (queued, opt) => {
      Internal.setQueued(opt, queued);
      opt;
    };
};

type t = BenchmarkJs__Types.options;

include Impl({
    type nonrec t = t;
    type eventHandler = BenchmarkJs__Types.eventHandler;
    type testFn = BenchmarkJs__Types.testFn;
    type setupFn = BenchmarkJs__Types.setupFn;
    type teardownFn = BenchmarkJs__Types.teardownFn;
});