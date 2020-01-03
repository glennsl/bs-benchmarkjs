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
type testFn = (. unit) => unit;
type setupFn = (. unit) => unit;
type teardownFn = (. unit) => unit;
type eventHandler = (. event) => unit;
type eventType = [ | `abort | `complete | `cycle | `error | `reset | `start | `unknown];

let eventTypeFromString: string => eventType =
  fun
  | "abort" => `abort
  | "complete" => `complete
  | "cycle" => `cycle
  | "error" => `error
  | "reset" => `reset
  | "start" => `start
  | _ => `unknown;

let eventTypeToString: eventType => string =
  fun
  | `abort => "abort"
  | `complete => "complete"
  | `cycle => "cycle"
  | `error => "error"
  | `reset => "reset"
  | `start => "start"
  | `unknown => "";

module Benchmark = {
  
  type t = benchmark;
  
  module Internal = {

    [@bs.module "benchmark"] [@bs.new] external make: (string, testFn) => t = "Benchmark";
    [@bs.module "benchmark"] [@bs.new] external makeWithOptions: (string, testFn, options) => t = "Benchmark";

    [@bs.send.pipe: t] external run: t = "run";
    [@bs.send.pipe: t] external runWithOptions: options => t = "run";

    [@bs.send.pipe: t] external clone: t => t = "clone";
    [@bs.send.pipe: t] external cloneWithOptions: (t, options) => t = "clone";

  };

  let make: (~options: options=?, string, testFn) => t = (~options=?, name, fn) =>
    switch (options) {
    | (None) => Internal.make(name, fn)
    | (Some(opt)) => Internal.makeWithOptions(name, fn, opt)
    };

  let run: (~options: options=?, t) => t = (~options=?, benchmark) =>
    switch (options) {
    | None => Internal.run(benchmark)
    | Some(opt) => Internal.runWithOptions(opt, benchmark)
    };

  let clone: (~options: options=?, t, t) => t =
    (~options=?, benchmark) =>
      switch (options) {
      | None => Internal.clone(benchmark)
      | Some(opt) => Internal.cloneWithOptions(benchmark, opt)
      };

  [@bs.get] external getAborted: t => bool = "aborted";

  [@bs.get] external getCompiled: t => testFn = "compiled";
  
  [@bs.get] external getCycles: t => int = "cycles";
  
  [@bs.get] external getCount: t => int = "count";
  
  [@bs.get] external getError: t => Js.Null_undefined.t(Js.Exn.t) = "error";
  
  [@bs.get] external getFn: t => testFn = "fn";
  
  [@bs.get] external getHz: t => float = "hz";
  
  [@bs.get] external getRunning: t => bool = "running";
  
  [@bs.get] external getSetup: t => setupFn = "setup";
  
  [@bs.get] external getStats: t => stats = "stats";
  
  [@bs.get] external getTeardown: t => teardownFn = "teardown";
  
  [@bs.get] external getTime: t => times = "time";
  
  [@bs.get] external getName: t => string = "name";
  
  [@bs.get] external getOptions: t => options = "options";
      
  [@bs.send.pipe: t] external abort: t = "abort";
  
  [@bs.send.pipe: t] external toString: string = "toString";
  
  [@bs.send.pipe: t] external cmp: t => int = "compare";
  
  [@bs.send.pipe: t] external reset: t = "reset";
  
};

module Deferred = {
  
  type t = deferred;
  
  [@bs.get] external getBenchmark: t => benchmark = "benchmark";

  [@bs.get] external getCycle: t => float = "cycle";
  
  [@bs.get] external getElapsed: t => float = "elapsed";
  
  [@bs.get] external getTimeStamp: t => float = "timeStamp";
  
};

module Event = {

  type t = event;

  [@bs.module "benchmark"] [@bs.scope "Benchmark"] [@bs.new] external make: string => t = "Event";
  
  [@bs.module "benchmark"] [@bs.scope "Benchmark"] [@bs.new] external fromEvent: t => t = "Event";
  
  [@bs.get] external getAborted: t => bool = "aborted";

  [@bs.get] external getCancelled: t => bool = "cancelled";
  
  [@bs.get] external getCurrentTarget: t => benchmark = "currentTarget";
  
  [@bs.get] external getResult: t => 'a = "result";
  
  [@bs.get] external getTarget: t => benchmark = "target";
  
  [@bs.get] external getTimeStamp: t => int = "timeStamp";
  
  [@bs.get] external getType: t => string = "type";
  
  let getType: t => eventType = (event) => eventTypeFromString(getType(event));

};

module Options = {

  type t = options;

  module Internal = {

    [@bs.get] external getAsync: t => Js.Nullable.t(bool) = "async";
    [@bs.get] external getDefer: t => Js.Nullable.t(bool) = "defer";
    [@bs.get] external getDelay: t => Js.Nullable.t(float) = "delay";
    [@bs.get] external getId: t => Js.Nullable.t(string) = "id";
    [@bs.get] external getInitCount: t => Js.Nullable.t(int) = "initCount";
    [@bs.get] external getMaxTime: t => Js.Nullable.t(float) = "maxTime";
    [@bs.get] external getMinSamples: t => Js.Nullable.t(int) = "minSamples";
    [@bs.get] external getMinTime: t => Js.Nullable.t(float) = "minTime";
    [@bs.get] external getName: t => Js.Nullable.t(string) = "name";
    [@bs.get] external getOnAbort: t => Js.Nullable.t(eventHandler) = "onAbort";
    [@bs.get] external getOnComplete: t => Js.Nullable.t(eventHandler) = "onComplete";
    [@bs.get] external getOnCycle: t => Js.Nullable.t(eventHandler) = "onCycle";
    [@bs.get] external getOnError: t => Js.Nullable.t(eventHandler) = "onError";
    [@bs.get] external getOnReset: t => Js.Nullable.t(eventHandler) = "onReset";
    [@bs.get] external getOnStart: t => Js.Nullable.t(eventHandler) = "onStart";
    [@bs.get] external getFn: t => Js.Nullable.t(testFn) = "fn";
    [@bs.get] external getSetup: t => Js.Nullable.t(setupFn) = "setup";
    [@bs.get] external getTeardown: t => Js.Nullable.t(teardownFn) = "teardown";
    [@bs.get] external getQueued: t => Js.Nullable.t(bool) = "queued";

    [@bs.set] external setAsync: (t, bool) => unit = "async";
    [@bs.set] external setDefer: (t, bool) => unit = "defer";
    [@bs.set] external setDelay: (t, float) => unit = "delay";
    [@bs.set] external setId: (t, string) => unit = "id";
    [@bs.set] external setInitCount: (t, int) => unit = "initCount";
    [@bs.set] external setMaxTime: (t, float) => unit = "maxTime";
    [@bs.set] external setMinSamples: (t, int) => unit = "minSamples";
    [@bs.set] external setMinTime: (t, float) => unit = "minTime";
    [@bs.set] external setName: (t, string) => unit = "name";
    [@bs.set] external setOnAbort: (t, eventHandler) => unit = "onAbort";
    [@bs.set] external setOnComplete: (t, eventHandler) => unit = "onComplete";
    [@bs.set] external setOnCycle: (t, eventHandler) => unit = "onCycle";
    [@bs.set] external setOnError: (t, eventHandler) => unit = "onError";
    [@bs.set] external setOnReset: (t, eventHandler) => unit = "onReset";
    [@bs.set] external setOnStart: (t, eventHandler) => unit = "onStart";
    [@bs.set] external setFn: (t, testFn) => unit = "fn";
    [@bs.set] external setSetup: (t, setupFn) => unit = "setup";
    [@bs.set] external setTeardown: (t, teardownFn) => unit = "teardown";
    [@bs.set] external setQueued: (t, bool) => unit = "queued";

    let nullToOption = Js.Nullable.toOption;

  };


  // getters
  let getAsync: t => option(bool) = Internal.(options => getAsync(options)->nullToOption);
  
  let getDefer: t => option(bool) = Internal.(options => getDefer(options)->nullToOption);
  
  let getDelay: t => option(float) = Internal.(options => getDelay(options)->nullToOption);
  
  let getId: t => option(string) = Internal.(options => getId(options)->nullToOption);
  
  let getInitCount: t => option(int) = Internal.(options => getInitCount(options)->nullToOption);
  
  let getMaxTime: t => option(float) = Internal.(options => getMaxTime(options)->nullToOption);
  
  let getMinSamples: t => option(int) = Internal.(options => getMinSamples(options)->nullToOption);
  
  let getMinTime: t => option(float) = Internal.(options => getMinTime(options)->nullToOption);
  
  let getName: t => option(string) = Internal.(options => getName(options)->nullToOption);
  
  let getOnAbort: t => option(eventHandler) = Internal.(options => getOnAbort(options)->nullToOption);
  
  let getOnComplete: t => option(eventHandler) = Internal.(options => getOnComplete(options)->nullToOption);
  
  let getOnCycle: t => option(eventHandler) = Internal.(options => getOnCycle(options)->nullToOption);
  
  let getOnError: t => option(eventHandler) = Internal.(options => getOnError(options)->nullToOption);
  
  let getOnReset: t => option(eventHandler) = Internal.(options => getOnReset(options)->nullToOption);
  
  let getOnStart: t => option(eventHandler) = Internal.(options => getOnStart(options)->nullToOption);
  
  let getFn: t => option(testFn) = Internal.(options => getFn(options)->nullToOption);
  
  let getSetup: t => option(setupFn) = Internal.(options => getSetup(options)->nullToOption);
  
  let getTeardown: t => option(teardownFn) = Internal.(options => getTeardown(options)->nullToOption);
  
  let getQueued: t => option(bool) = Internal.(options => getQueued(options)->nullToOption);

  // setters
  let setAsync: (bool, t) => t = (async, opt) => { Internal.setAsync(opt, async); opt; };
  
  let setDefer: (bool, t) => t = (defer, opt) => { Internal.setDefer(opt, defer); opt; };
  
  let setDelay: (float, t) => t = (delay, opt) => { Internal.setDelay(opt, delay); opt; };
  
  let setId: (string, t) => t = (id, opt) => { Internal.setId(opt, id); opt; };

  let setInitCount: (int, t) => t = (initCount, opt) => { Internal.setInitCount(opt, initCount); opt; };
  
  let setMaxTime: (float, t) => t = (maxTime, opt) => { Internal.setMaxTime(opt, maxTime); opt; };
  
  let setMinSamples: (int, t) => t = (minSamples, opt) => { Internal.setMinSamples(opt, minSamples); opt; };
  
  let setMinTime: (float, t) => t = (minTime, opt) => { Internal.setMinTime(opt, minTime); opt; };
  
  let setName: (string, t) => t = (name, opt) => { Internal.setName(opt, name); opt; };
  
  let setOnAbort: (eventHandler, t) => t = (onAbort, opt) => { Internal.setOnAbort(opt, onAbort); opt; };
  
  let setOnComplete: (eventHandler, t) => t = (onComplete, opt) => { Internal.setOnComplete(opt, onComplete); opt; };
  
  let setOnCycle: (eventHandler, t) => t = (onCycle, opt) => { Internal.setOnCycle(opt, onCycle); opt; };
  
  let setOnError: (eventHandler, t) => t = (onError, opt) => { Internal.setOnError(opt, onError); opt; };
  
  let setOnReset: (eventHandler, t) => t = (onReset, opt) => { Internal.setOnReset(opt, onReset); opt; };
  
  let setOnStart: (eventHandler, t) => t = (onStart, opt) => { Internal.setOnStart(opt, onStart); opt; };
  
  let setFn: (testFn, t) => t = (fn, opt) => { Internal.setFn(opt, fn); opt; };
  
  let setSetup: (setupFn, t) => t = (setup, opt) => { Internal.setSetup(opt, setup); opt; };
  
  let setTeardown: (teardownFn, t) => t = (teardown, opt) => { Internal.setTeardown(opt, teardown); opt; };
  
  let setQueued: (bool, t) => t = (queued, opt) => { Internal.setQueued(opt, queued); opt; };

  // others
  let copy: t => t = options => Glennsl__BsBenchmarkJs__JsUtils.Obj.shallowCopy(. options);
  
  let empty: unit => t = () => Glennsl__BsBenchmarkJs__JsUtils.Obj.empty(.);

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
        ~onAbort: option(eventHandler)=?,
        ~onComplete: option(eventHandler)=?,
        ~onCycle: option(eventHandler)=?,
        ~onError: option(eventHandler)=?,
        ~onReset: option(eventHandler)=?,
        ~onStart: option(eventHandler)=?,
        ~fn: option(testFn)=?,
        ~setup: option(setupFn)=?,
        ~teardown: option(teardownFn)=?,
        ~queued: option(bool)=?,
        (),
      ) => {

    let opt: t = empty();

    let () = {
      switch (async) { | None => () | Some(x) => Internal.setAsync(opt, x) };
      switch (defer) { | None => () | Some(x) => Internal.setDefer(opt, x) };
      switch (delay) { | None => () | Some(x) => Internal.setDelay(opt, x) };
      switch (id) { | None => () | Some(x) => Internal.setId(opt, x) };
      switch (initCount) { | None => () | Some(x) => Internal.setInitCount(opt, x) };
      switch (maxTime) { | None => () | Some(x) => Internal.setMaxTime(opt, x) };
      switch (minSamples) { | None => () | Some(x) => Internal.setMinSamples(opt, x) };
      switch (minTime) { | None => () | Some(x) => Internal.setMinTime(opt, x) };
      switch (name) { | None => () | Some(x) => Internal.setName(opt, x) };
      switch (onAbort) { | None => () | Some(x) => Internal.setOnAbort(opt, x) };
      switch (onComplete) { | None => () | Some(x) => Internal.setOnComplete(opt, x) };
      switch (onCycle) { | None => () | Some(x) => Internal.setOnCycle(opt, x) };
      switch (onError) { | None => () | Some(x) => Internal.setOnError(opt, x) };
      switch (onReset) { | None => () | Some(x) => Internal.setOnReset(opt, x) };
      switch (onStart) { | None => () | Some(x) => Internal.setOnStart(opt, x) };
      switch (fn) { | None => () | Some(x) => Internal.setFn(opt, x) };
      switch (setup) { | None => () | Some(x) => Internal.setSetup(opt, x) };
      switch (teardown) { | None => () | Some(x) => Internal.setTeardown(opt, x) };
      switch (queued) { | None => () | Some(x) => Internal.setQueued(opt, x) };
    };
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
        ~onAbort: option(eventHandler)=?,
        ~onComplete: option(eventHandler)=?,
        ~onCycle: option(eventHandler)=?,
        ~onError: option(eventHandler)=?,
        ~onReset: option(eventHandler)=?,
        ~onStart: option(eventHandler)=?,
        ~fn: option(testFn)=?,
        ~setup: option(setupFn)=?,
        ~teardown: option(teardownFn)=?,
        ~queued: option(bool)=?,
        options: t,
      ) => {

    let opt: t = copy(options);
    
    let () = {
      switch (async) { | None => () | Some(x) => Internal.setAsync(opt, x) };
      switch (defer) { | None => () | Some(x) => Internal.setDefer(opt, x) };
      switch (delay) { | None => () | Some(x) => Internal.setDelay(opt, x) };
      switch (id) { | None => () | Some(x) => Internal.setId(opt, x) };
      switch (initCount) { | None => () | Some(x) => Internal.setInitCount(opt, x) };
      switch (maxTime) { | None => () | Some(x) => Internal.setMaxTime(opt, x) };
      switch (minSamples) { | None => () | Some(x) => Internal.setMinSamples(opt, x) };
      switch (minTime) { | None => () | Some(x) => Internal.setMinTime(opt, x) };
      switch (name) { | None => () | Some(x) => Internal.setName(opt, x) };
      switch (onAbort) { | None => () | Some(x) => Internal.setOnAbort(opt, x) };
      switch (onComplete) { | None => () | Some(x) => Internal.setOnComplete(opt, x) };
      switch (onCycle) { | None => () | Some(x) => Internal.setOnCycle(opt, x) };
      switch (onError) { | None => () | Some(x) => Internal.setOnError(opt, x) };
      switch (onReset) { | None => () | Some(x) => Internal.setOnReset(opt, x) };
      switch (onStart) { | None => () | Some(x) => Internal.setOnStart(opt, x) };
      switch (fn) { | None => () | Some(x) => Internal.setFn(opt, x) };
      switch (setup) { | None => () | Some(x) => Internal.setSetup(opt, x) };
      switch (teardown) { | None => () | Some(x) => Internal.setTeardown(opt, x) };
      switch (queued) { | None => () | Some(x) => Internal.setQueued(opt, x) };
    };
    opt;
  };
  
};

/**
 * [ Platform ]
 *
 * Contains functions for getting information about the host environment,
 * including the browser/runtime, operating system, physical device model,
 * device manufacturer, etc.
 *
 * All of the values are initialized when the code is first loaded
 * by the runtime.
 */
module Platform = {

  module OS = {

    [@bs.module "benchmark"] [@bs.scope ("Benchmark", "platform", "os")] [@bs.val] external architecture: Js.Nullable.t(string) = "architecture";
    /** [ architecture ] The orchitecture of the operating system. */
    let architecture = Js.Nullable.toOption(architecture);
    
    [@bs.module "benchmark"] [@bs.scope ("Benchmark", "platform", "os")] [@bs.val] external family: Js.Nullable.t(string) = "family";
    /** [ family ] The operating system family. */
    let family = Js.Nullable.toOption(family);
    
    [@bs.module "benchmark"] [@bs.scope ("Benchmark", "platform", "os")] [@bs.val] external version: Js.Nullable.t(string) = "version";
    /** [ version ] The version name/number of the operating system. */
    let version = Js.Nullable.toOption(version);
    
    /** [ toString ] Returns the description of the OS, or an empty string if the description is unavailable. */
    [@bs.module "benchmark"] [@bs.scope ("Benchmark", "platform", "os")] [@bs.val] external toString: unit => string = "toString";
    
  };

  [@bs.module "benchmark"] [@bs.scope ("Benchmark", "platform")] [@bs.val] external description: Js.Nullable.t(string) = "description";
  /** [ description ] A short string describing the host operating system and runtime platform. */
  let description = Js.Nullable.toOption(description);
  
  [@bs.module "benchmark"] [@bs.scope ("Benchmark", "platform")] [@bs.val] external layout: Js.Nullable.t(string) = "layout";
  /** [ layout ] The host platform's JS interpreter engine. E.g. "WebKit", "V8", "SpiderMonkey". */
  let layout = Js.Nullable.toOption(layout);
  
  [@bs.module "benchmark"] [@bs.scope ("Benchmark", "platform")] [@bs.val] external product: Js.Nullable.t(string) = "product";
  /** [ product ] The host device name. E.g. "iPad", "Android Galaxy S3". */
  let product = Js.Nullable.toOption(product);
  
  [@bs.module "benchmark"] [@bs.scope ("Benchmark", "platform")] [@bs.val] external name: Js.Nullable.t(string) = "name";
  /** [ name ] The name of the host platfrom or browser. E.g. "Safari", "Node", "Firefox". */
  let name = Js.Nullable.toOption(name);
  
  [@bs.module "benchmark"] [@bs.scope ("Benchmark", "platform")] [@bs.val] external manufacturer: Js.Nullable.t(string) = "manufacturer";
  /** [ manufacturer ] The name of the device manufacturer. E.g. "HP", "Apple", "Microsoft". */
  let manufacturer = Js.Nullable.toOption(manufacturer);
  
  [@bs.module "benchmark"] [@bs.scope ("Benchmark", "platform")] [@bs.val] external prerelease: Js.Nullable.t(string) = "prerelease";
  /** [ prerelease ] The aplph/beta release indicator. */
  let prerelease = Js.Nullable.toOption(prerelease);
  
  [@bs.module "benchmark"] [@bs.scope ("Benchmark", "platform")] [@bs.val] external version: Js.Nullable.t(string) = "version";
  /** [ version ] The version of the host operating system. */
  let version = Js.Nullable.toOption(version);
  
  /** [ toString() ] Returns the [ description ] property (string) or an empty string if the description is not available. */
  [@bs.module "benchmark"] [@bs.scope ("Benchmark", "platform")] [@bs.val] external toString: unit => string = "toString";

};

module Stats = {

  type t = stats;

  /** [ getDeviation(stats) ] Returns the standard deviation of the benchmark sample. */
  [@bs.get] external getDeviation: t => float = "deviation";
  
  /** [ getMean(stats) ] Returns the mean of the benchmark sample. */
  [@bs.get] external getMean: t => float = "mean";
  
  /** [ getMOE(stats) ] Returns the margin of error of the benchmark sample. */
  [@bs.get] external getMOE: t => float = "moe";
  
  /** [ getRME(stats) ] Returns the relative margin of error of the benchmark sample. */
  [@bs.get] external getRME: t => float = "rme";
  
  /** [ getSample(stats) ] Returns an array of sampled time periods. */
  [@bs.get] external getSample: t => array(float) = "sample";
  
  /** [ getSEM(stats) ] Returns the standard error of the mean of the benchmark sample. */
  [@bs.get] external getSEM: t => float = "sem";
  
  /** [ getVariance(stats) ] Returns the variance of the benchmark sample. */
  [@bs.get] external getVariance: t => float = "variance";

};

module SuiteOptions = {

  type t = suiteOptions;

  [@bs.get] external getName: t => Js.Nullable.t(string) = "name";
  [@bs.get] external getOnAbort: t => Js.Nullable.t(eventHandler) = "onAbort";
  [@bs.get] external getOnComplete: t => Js.Nullable.t(eventHandler) = "onComplete";
  [@bs.get] external getOnCycle: t => Js.Nullable.t(eventHandler) = "onCycle";
  [@bs.get] external getOnError: t => Js.Nullable.t(eventHandler) = "onError";
  [@bs.get] external getOnReset: t => Js.Nullable.t(eventHandler) = "onReset";
  [@bs.get] external getOnStart: t => Js.Nullable.t(eventHandler) = "onStart";

  [@bs.set] external setName: (t, string) => unit = "name";
  [@bs.set] external setOnAbort: (t, eventHandler) => unit = "onAbort";
  [@bs.set] external setOnComplete: (t, eventHandler) => unit = "onComplete";
  [@bs.set] external setOnCycle: (t, eventHandler) => unit = "onCycle";
  [@bs.set] external setOnError: (t, eventHandler) => unit = "onError";
  [@bs.set] external setOnReset: (t, eventHandler) => unit = "onReset";
  [@bs.set] external setOnStart: (t, eventHandler) => unit = "onStart";

  /**
   * [ make(...options) ]
   * Creates a new [ suiteOptions ] object with the specified properties.
   * All properties on the object are optional.
   */
  let make:
    (
      ~name: string=?,
      ~onAbort: eventHandler=?,
      ~onComplete: eventHandler=?,
      ~onCycle: eventHandler=?,
      ~onError: eventHandler=?,
      ~onReset: eventHandler=?,
      ~onStart: eventHandler=?,
      unit
    ) =>
    t =
    (
      ~name: option(string)=?,
      ~onAbort: option(eventHandler)=?,
      ~onComplete: option(eventHandler)=?,
      ~onCycle: option(eventHandler)=?,
      ~onError: option(eventHandler)=?,
      ~onReset: option(eventHandler)=?,
      ~onStart: option(eventHandler)=?,
      ()
    ) => {
      let opt = Glennsl__BsBenchmarkJs__JsUtils.Obj.empty(. );
      let () = {
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
      };
      opt;
    };

  /** [ getName(suiteOptions) ] returns the 'name' property assigned to [suiteOptions]. */
  let getName: t => option(string) = (opt) => Js.Nullable.toOption(getName(opt));
  
  /** [ getOnAbort(suiteOptions) ] returns the 'onAbort' event listener assigned to [suiteOptions]. */
  let getOnAbort: t => option(eventHandler) = (opt) => Js.Nullable.toOption(getOnAbort(opt));
  
  /** [ getOnComplete(suiteOptions) ] returns the 'onComplete' event listener assigned to [suiteOptions]. */
  let getOnComplete: t => option(eventHandler) = (opt) => Js.Nullable.toOption(getOnComplete(opt));
  
  /** [ getOnCycle(suiteOptions) ] returns the 'onCycle' event listener assigned to [suiteOptions]. */
  let getOnCycle: t => option(eventHandler) = (opt) => Js.Nullable.toOption(getOnCycle(opt));
  
  /** [ getOnError(suiteOptions) ] returns the 'onError' event listener assigned to [suiteOptions]. */
  let getOnError: t => option(eventHandler) = (opt) => Js.Nullable.toOption(getOnError(opt));
  
  /** [ getOnReset(suiteOptions) ] returns the 'onReset' event listener assigned to [suiteOptions]. */
  let getOnReset: t => option(eventHandler) = (opt) => Js.Nullable.toOption(getOnReset(opt));
  
  /** [ getOnStart(suiteOptions) ] returns the 'onStart' event listener assigned to [suiteOptions]. */
  let getOnStart: t => option(eventHandler) = (opt) => Js.Nullable.toOption(getOnStart(opt));

  /** [ setName(suiteOptions) ] mutates [ suiteOptions ] by setting its 'name' property. */
  let setName: (string, suiteOptions) => suiteOptions = (name, opt) => { setName(opt, name); opt; };

  /** [ setOnAbort(suiteOptions) ] mutates [ suiteOptions ] by setting its 'onAbort' property. */
  let setOnAbort: (eventHandler, suiteOptions) => suiteOptions = (name, opt) => { setOnAbort(opt, name); opt; };

  /** [ setOnComplete(suiteOptions) ] mutates [ suiteOptions ] by setting its 'onComplete' property. */
  let setOnComplete: (eventHandler, suiteOptions) => suiteOptions = (name, opt) => { setOnComplete(opt, name); opt; };
  
  /** [ setOnCycle(suiteOptions) ] mutates [ suiteOptions ] by setting its 'onCycle' property. */
  let setOnCycle: (eventHandler, suiteOptions) => suiteOptions = (name, opt) => { setOnCycle(opt, name); opt; };
  
  /** [ setOnError(suiteOptions) ] mutates [ suiteOptions ] by setting its 'onError' property. */
  let setOnError: (eventHandler, suiteOptions) => suiteOptions = (name, opt) => { setOnError(opt, name); opt; };
  
  /** [ setOnReset(suiteOptions) ] mutates [ suiteOptions ] by setting its 'onReset' property. */
  let setOnReset: (eventHandler, suiteOptions) => suiteOptions = (name, opt) => { setOnReset(opt, name); opt; };
  
  /** [ setOnStart(suiteOptions) ] mutates [ suiteOptions ] by setting its 'onStart' property. */
  let setOnStart: (eventHandler, suiteOptions) => suiteOptions = (name, opt) => { setOnStart(opt, name); opt; };

};

module Suite = {

  type t = suite;

  module Internal = {

    [@bs.module "benchmark"] [@bs.scope "Benchmark"] [@bs.new] external make: string => t = "Suite";
    [@bs.module "benchmark"] [@bs.scope "Benchmark"] [@bs.new] external makeWithOptions: (string, suiteOptions) => t = "Suite";
    [@bs.send.pipe: t] external add: (string, testFn) => t = "add";
    [@bs.send.pipe: t] external addWithOptions: (string, testFn, options) => t = "add";
    [@bs.send.pipe: t] external run: t = "run";
    [@bs.send.pipe: t] external runWithOptions: suiteOptions => t = "run";
    [@bs.send.pipe: t] external clone: t = "clone";
    [@bs.send.pipe: t] external cloneWithOptions: suiteOptions => t = "clone";
    [@bs.send.pipe: t] external emit: string => t = "emit";
    [@bs.send.pipe: t] external getListeners: array(eventHandler) = "listeners";
    [@bs.send.pipe: t] external getListenersByEvent: string => array(eventHandler) = "listeners";
    [@bs.send.pipe: t] external removeListener: (string, eventHandler) => t = "off";
    [@bs.send.pipe: t] external removeListenersByEvent: string => t = "off";
    [@bs.send.pipe: t] external removeAllListeners: t = "off";
    [@bs.send.pipe: t] external on: (string, eventHandler) => t = "on";
    let eventListToString: list(eventType) => string =
      eventList =>
        Belt.List.reduceU(eventList, "", (. str, evt) => {
          str ++ eventTypeToString(evt) ++ " "
        });
    let addBenchmarkToSuite: (. t, benchmark) => t =
      (. suite, bench) =>
        addWithOptions(
          Benchmark.getName(bench),
          Benchmark.getFn(bench),
          Benchmark.getOptions(bench),
          suite,
        );

  };

  /**
   * [ getName(suite) ]
   * Returns the name of [ suite ].
   */
  [@bs.get] [@bs.scope "options"] external getName: t => string = "name";

  /**
   * [ getAborted(suite) ]
   * Returns true if [ suite ] was aborted during a run.
   */
  [@bs.get] external getAborted: t => bool = "aborted";
  
  /**
   * [ getLength(suite) ]
   * Returns the number of benchmark instances in [ suite ].
   */
  [@bs.get] external getLength: t => int = "length";
  
  /**
   * [ getRunning(suite) ]
   * Returns true if [ suite ] is currently running.
   */
  [@bs.get] external getRunning: t => bool = "running";
  
  /**
   * [ make(~options=?, name) ]
   * Creates a new suite and assigns [ name ] and [ options ] to its 'name' property.
   * Benchmarks can be added to the suite using the [ add ] function.
   */
  let make: (~options: suiteOptions=?, string) => t =
    (~options=?, name) =>
      switch (options) {
      | None => Internal.make(name)
      | Some(opt) => Internal.makeWithOptions(name, opt)
      };

  /**
   * [ add(~options=?, name, fn, suite) ]
   * Creates a new Benchmark.t from the provided arguments, adds it to [ suite ],
   * and returns the same [ suite ].
   */
  let add: (~options: options=?, string, testFn, t) => t =
    (~options=?, name, fn, suite) =>
      switch (options) {
      | None => Internal.add(name, fn, suite)
      | Some(opt) => Internal.addWithOptions(name, fn, opt, suite)
      };

  /**
   * [ run(~options=?, suite) ]
   * Runs all the benchmark functions in [ suite ], emits the [ `start ] event, and returns [ suite ].
   */
  let run: (~options: suiteOptions=?, t) => t =
    (~options=?, suite) =>
      switch (options) {
      | None => Internal.run(suite)
      | Some(opt) => Internal.runWithOptions(opt, suite)
      };

  /**
   * [ clone(~options=?, suite) ]
   * Returns a clone of [ suite ].
   */
  let clone: (~options: suiteOptions=?, t) => t =
    (~options=?, suite) =>
      switch (options) {
      | None => Internal.clone(suite)
      | Some(opt) => Internal.cloneWithOptions(opt, suite)
      };
  
  
  /** 
   * [ emitFromEvent(event, suite) ]
   * emits a new event of the same type as [ event ], calling the associated event listeners
   * and returns [suite].
   */
  [@bs.send.pipe: t] external emitFromEvent: event => t = "emit";
  
  /**
   * [ emit(eventType, suite) ]
   * Calls each event listener in [ suite ] that is listening to the event of type [ eventType ].
   */
  let emit: (eventType, t) => t = (eventType, suite) => Internal.emit(eventTypeToString(eventType), suite);
  
  /**
   * [ onAbort(eventListener, suite) ]
   * Adds [ eventListener ] to [ suite ] that will be called during the [ `abort ] event.
   */
  let onAbort: (eventHandler, t) => t = (handler, suite) => Internal.on("abort", handler, suite);
  
  /**
   * [ onComplete(eventListener, suite) ]
   * Adds [ eventListener ] to [ suite ] that will be called during the [ `complete ] event.
   */
  let onComplete: (eventHandler, t) => t = (handler, suite) => Internal.on("complete", handler, suite);
  
  /**
   * [ onCycle(eventListener, suite) ]
   * Adds [ eventListener ] to [ suite ] that will be called during the [ `cycle ] event.
   */
  let onCycle: (eventHandler, t) => t = (handler, suite) => Internal.on("cycle", handler, suite);
  
  /**
   * [ onErrar(eventListener, suite) ]
   * Adds [ eventListener ] to [ suite ] that will be called during the [ `error ] event.
   */
  let onError: (eventHandler, t) => t = (handler, suite) => Internal.on("error", handler, suite);
  
  /**
   * [ onReset(eventListener, suite) ]
   * Adds [ eventListener ] to [ suite ] that will be called during the [ `reset ] event.
   */
  let onReset: (eventHandler, t) => t = (handler, suite) => Internal.on("reset", handler, suite);
  
  /**
   * [ onStart(eventListener, suite) ]
   * Adds [ eventListener ] to [ suite ] that will be called during the [ `start ] event.
   */
  let onStart: (eventHandler, t) => t = (handler, suite) => Internal.on("start", handler, suite);
  
  /**
   * [ on(eventList, eventListener, suite) ]
   * Adds [ eventListener ] to [ suite ] that will be called during each event specified in [ eventList ],
   * and returns [ suite ].
   */
  let on: (list(eventType), eventHandler, t) => t =
    (eventList, handler, suite) => Internal.(eventListToString(eventList)->on(handler, suite));
  
  /**
   * [ abort(suite) ]
   * Aborts [ suite ] if it is currently running, and triggers the [ `abort ] event.
   */
  [@bs.send.pipe: t] external abort: t = "abort";
  
  /**
   * [ reset(suite) ]
   * Resets [ suite ], and triggers the [ `reset ] event.
   */
  [@bs.send.pipe: t] external reset: t = "reset";
  
  /**
   * [ toArray(suite) ]
   * Returns an array of all the benchmarks that are currently assigned to [ suite ].
   */
  [@bs.val] [@bs.scope ("Array", "prototype", "slice")] external toArray: t => array(benchmark) = "call";
  
  /**
   * [ toList(suite) ]
   * Returns an list of all the benchmarks that are currently assigned to [ suite ].
   */
  let toList: t => list(benchmark) = suite => toArray(suite)->Belt.List.fromArray;
  
  /**
   * [ fromArray(~options=?, name, benchmarkArray) ]
   * Adds all benchmark objects in [ benchmarkArray ] them all to a new suite instance,
   * setting [ name ] and [ options ] to the suite's 'name' and 'options' properties, respectively.
   */
  let fromArray: (~options: suiteOptions=?, string, array(benchmark)) => t =
    (~options=?, name, benchArray) => {
      let suite =
        switch (options) {
        | None => make(name)
        | Some(opt) => make(name, ~options=opt)
        };
      Belt.Array.reduceU(benchArray, suite, Internal.addBenchmarkToSuite);
    };

  /**
   * [ fromArray(~options=?, name, benchmarkList) ]
   * Adds all benchmark objects in [ benchmarkList ] them all to a new suite instance,
   * setting [ name ] and [ options ] to the suite's 'name' and 'options' properties, respectively.
   */
  let fromList: (~options: suiteOptions=?, string, list(benchmark)) => t =
    (~options=?, name, benchList) => {
      let suite =
        switch (options) {
        | None => make(name)
        | Some(opt) => make(name, ~options=opt)
        };
      Belt.List.reduceU(benchList, suite, Internal.addBenchmarkToSuite);
    };

  /**
   * [ getListeners(suite) ]
   * Returns an array of all the event listener functions that are listening
   * to the suite's events.
   */
  let getListeners: t => array(eventHandler) = Internal.getListeners;

  /**
   * [ getListenersByEvent(suite) ]
   * Returns an array of even listeners that are listeneng to the specified
   * event type.
   */
  let getListenersByEvent: (eventType, t) => array(eventHandler) =
    (eventType, suite) => Internal.getListenersByEvent(eventTypeToString(eventType), suite);

  /**
   * [ removeListener(eventList, eventListener, suite) ]
   * Removes [ eventListener ] from [ suite ]. The listener function is identified
   * by a physical (reference) equality check, so the exact reference must
   * be provided, along with the event type(s) it is listening to.
   */
  let removeListener: (list(eventType), eventHandler, t) => t =
    (eventList, handler, suite) =>
      Internal.(eventListToString(eventList)->removeListener(handler, suite));

  /**
   * [ removeListenersByEvent(eventList, suite) ]
   * Removes all event listeners from [ suite ] which correspond to the
   * the event types sepecified in [ eventList ], and returns [ suite ].
   */
  let removeListenersByEvent: (list(eventType), t) => t =
    (eventList, suite) =>
      Internal.(eventListToString(eventList)->removeListenersByEvent(suite));

  /**
   * [ removeAllListeners(suite) ]
   * Removes all the event listeners from [ suite ] and returns [ suite ].
   */
  let removeAllListeners: t => t = Internal.removeAllListeners;

  /**
   * [ filter(predicate, suite) ]
   * Filters the benchmarks in [ suite ] based on the return value of [predicate],
   * returning a new suite.
   */
  [@bs.send.pipe: t] external filter: (benchmark => bool) => t = "filter";

  /**
   * [ filterByFastest(name, suite) ]
   * Returns a new suite containing only the fastest benchmarks.
   */
  [@bs.send.pipe: t] external filterByFastest: ([@bs.as "fastest"] _) => t = "filter";
  
  /**
   * [ filterBySlowest(name, suite) ]
   * Returns a new suite containing only the slowest benchmarks.
   */
  [@bs.send.pipe: t] external filterBySlowest: ([@bs.as "slowest"] _) => t = "filter";
  
  /**
   * [ filterBySuccessful(name, suite) ]
   * Returns a new suite containing only the successful benchmarks.
   */
  [@bs.send.pipe: t] external filterBySuccessful: ([@bs.as "successful"] _) => t = "filter";

};

module Support = {

  [@bs.module "benchmark"] [@bs.scope ("Benchmark", "support")] external browser: bool = "browser";
  [@bs.module "benchmark"] [@bs.scope ("Benchmark", "support")] external timeout: bool = "timeout";
  [@bs.module "benchmark"] [@bs.scope ("Benchmark", "support")] external decompilation: bool = "decompilation";

};

module Times = {

  type t = times;

  [@bs.get] external getCycle: t => float = "cycle";
  
  [@bs.get] external getElapsed: t => float = "elapsed";
  
  [@bs.get] external getPeriod: t => float = "period";
  
  [@bs.get] external getTimeStamp: t => float = "timeStamp";
  
};

module Utils = {

  [@bs.module "benchmark"] [@bs.scope "Benchmark"] external formatNumber: float => string = "formatNumber";
  
  /** [ filterBenchmarks(benchmarkArray, predicate) ]:
   *  Filters an array of benchmark objects based on
   *  the return value of the predicate function.
   */
  [@bs.module "benchmark"] [@bs.scope "Benchmark"] external filterBenchmarks: (array(benchmark), benchmark => bool) => array(benchmark) = "filter";

  [@bs.module "benchmark"] [@bs.scope "Benchmark"] external filterByFastest: (array(benchmark), [@bs.as "fastest"] _) => array(benchmark) = "filter";
  
  [@bs.module "benchmark"] [@bs.scope "Benchmark"] external filterBySlowest: (array(benchmark), [@bs.as "slowest"] _) => array(benchmark) = "filter";
  
  [@bs.module "benchmark"] [@bs.scope "Benchmark"] external filterBySuccessful: (array(benchmark), [@bs.as "successful"] _) => array(benchmark) = "filter";

};