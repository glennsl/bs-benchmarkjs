type benchmark;
type suite;
type suiteOptions;
type deferred;
type event;
type testFn = (. unit) => unit;
type setupFn = (. unit) => unit;
type teardownFn = (. unit) => unit;
type eventHandler = (. event) => unit;
type eventType = [ | `abort | `complete | `cycle | `error | `reset | `start | `unknown];
type options;
type times;
type stats;
type platform;
type support;

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

  [@bs.get] external aborted: t => bool = "aborted";

  [@bs.get] external compiled: t => testFn = "compiled";
  
  [@bs.get] external cycles: t => int = "cycles";
  
  [@bs.get] external count: t => int = "count";
  
  [@bs.get] external error: t => Js.Null_undefined.t(Js.Exn.t) = "error";
  
  [@bs.get] external fn: t => testFn = "fn";
  
  [@bs.get] external hz: t => float = "hz";
  
  [@bs.get] external running: t => bool = "running";
  
  [@bs.get] external setup: t => setupFn = "setup";
  
  [@bs.get] external stats: t => stats = "stats";
  
  [@bs.get] external teardown: t => teardownFn = "teardown";
  
  [@bs.get] external time: t => times = "time";
  
  [@bs.get] external name: t => string = "name";
  
  [@bs.get] external options: t => options = "options";
      
  [@bs.send.pipe: t] external abort: t = "abort";
  
  [@bs.send.pipe: t] external toString: string = "toString";
  
  [@bs.send.pipe: t] external compare: t => int = "compare";
  
  [@bs.send.pipe: t] external reset: t = "reset";
  
};

module Deferred = {
  
  type t = deferred;
  
  [@bs.get] external benchmark: t => benchmark = "benchmark";

  [@bs.get] external cycle: t => float = "cycle";
  
  [@bs.get] external elapsed: t => float = "elapsed";
  
  [@bs.get] external timeStamp: t => float = "timeStamp";
  
};

module Event = {

  type t = event;

  [@bs.module "benchmark"] [@bs.scope "Benchmark"] [@bs.new] external make: string => t = "Event";
  
  [@bs.module "benchmark"] [@bs.scope "Benchmark"] [@bs.new] external fromEvent: t => t = "Event";
  
  [@bs.get] external aborted: t => bool = "aborted";

  [@bs.get] external cancelled: t => bool = "cancelled";
  
  [@bs.get] external currentTarget: t => benchmark = "currentTarget";
  
  [@bs.get] external result: t => 'a = "result";
  
  [@bs.get] external target: t => benchmark = "target";
  
  [@bs.get] external timeStamp: t => int = "timeStamp";
  
  [@bs.get] external type_: t => string = "type";
  
  let type_: t => eventType = (event) => eventTypeFromString(type_(event));

};

module Options = {

  type t = options;

  [@bs.obj] external make: (
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
    unit,
  ) => t = "";

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

  /** [ deviation(stats) ] Returns the standard deviation of the benchmark sample. */
  [@bs.get] external deviation: t => float = "deviation";
  
  /** [ mean(stats) ] Returns the mean of the benchmark sample. */
  [@bs.get] external mean: t => float = "mean";
  
  /** [ moe(stats) ] Returns the margin of error of the benchmark sample. */
  [@bs.get] external moe: t => float = "moe";
  
  /** [ rme(stats) ] Returns the relative margin of error of the benchmark sample. */
  [@bs.get] external rme: t => float = "rme";
  
  /** [ sample(stats) ] Returns an array of sampled time periods. */
  [@bs.get] external sample: t => array(float) = "sample";
  
  /** [ sem(stats) ] Returns the standard error of the mean of the benchmark sample. */
  [@bs.get] external sem: t => float = "sem";
  
  /** [ variance(stats) ] Returns the variance of the benchmark sample. */
  [@bs.get] external variance: t => float = "variance";

};

module SuiteOptions = {

  type t = suiteOptions;

  /**
   * [ make(...options) ]
   * Creates a new [ suiteOptions ] object with the specified properties.
   * All properties on the object are optional.
   */

  [@bs.obj] external make:
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
    t = "";

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
    [@bs.send.pipe: t] external listeners: array(eventHandler) = "listeners";
    [@bs.send.pipe: t] external listenersByEvent: string => array(eventHandler) = "listeners";
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
          Benchmark.name(bench),
          Benchmark.fn(bench),
          Benchmark.options(bench),
          suite,
        );

  };

  /**
   * [ name(suite) ]
   * Returns the name of [ suite ].
   */
  [@bs.get] [@bs.scope "options"] external name: t => string = "name";

  /**
   * [ aborted(suite) ]
   * Returns true if [ suite ] was aborted during a run.
   */
  [@bs.get] external aborted: t => bool = "aborted";
  
  /**
   * [ length(suite) ]
   * Returns the number of benchmark instances contained in [ suite ].
   */
  [@bs.get] external length: t => int = "length";
  
  /**
   * [ running(suite) ]
   * Returns true if [ suite ] is currently running.
   */
  [@bs.get] external running: t => bool = "running";
  
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
   * Creates a new benchmark from the provided arguments, adds it to [ suite ],
   * and returns the same [ suite ].
   */
  let add: (~options: options=?, string, testFn, t) => t =
    (~options=?, name, fn, suite) =>
      switch (options) {
      | None => Internal.add(name, fn, suite)
      | Some(opt) => Internal.addWithOptions(name, fn, opt, suite)
      };
  
  let testAdd = add(~options=Options.make(~async = false, ()));

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
  let listeners: t => array(eventHandler) = Internal.listeners;

  /**
   * [ getListenersByEvent(suite) ]
   * Returns an array of even listeners that are listeneng to the specified
   * event type.
   */
  let getListenersByEvent: (eventType, t) => array(eventHandler) =
    (eventType, suite) => Internal.listenersByEvent(eventTypeToString(eventType), suite);

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

  // internal
  [@bs.val] [@bs.scope ("Array", "prototype", "push")] external addBenchmark: (t, benchmark) => unit = "call";

  // internal
  [@bs.val] [@bs.scope ("Array", "prototype", "push")] external addBenchmarkArray: (t, array(benchmark)) => unit = "apply";

  /**
   * [ addBenchmarkList(benchmarkList, suite) ]
   * Adds each benchmark from [ benchmarkList ] to [ suite ], and returns [ suite ].
   */
  let addBenchmarkList: (list(benchmark), t) => t = (benchmarkList, suite) => {
    benchmarkList |> Belt.List.toArray |> addBenchmarkArray(suite);
    suite;
  };

  /**
   * [ addBenchmarkArray(benchmark, suite) ]
   * Adds [ benchmark ] to [ suite ] and returns [ suite ].
   */
  let addBenchmark: (benchmark, t) => t = (benchmark, suite) => {
    addBenchmark(suite, benchmark);
    suite;
  };

  /**
   * [ addBenchmarkArray(benchmarkArray, suite) ]
   * Adds each benchmark from [ benchmarkArray ] to [ suite ] and returns [ suite ].
   */
  let addBenchmarkArray: (array(benchmark), t) => t = (benchmarkArray, suite) => {
    addBenchmarkArray(suite, benchmarkArray);
    suite;
  };

};

module Support = {

  /** [ browser ] Will be set to [ true ] if the code is running in a web browser context. */
  [@bs.module "benchmark"] [@bs.scope ("Benchmark", "support")] external browser: bool = "browser";

  /** [ timeout ] Will be set to [ true ] if the Timers API is made available by the host. */
  [@bs.module "benchmark"] [@bs.scope ("Benchmark", "support")] external timeout: bool = "timeout";

  /**
   * [ decompilation ]
   * Will be set to [ true ] if the host runtime supports features that enable code decompilation.
   * If true, Benchmark.js will decompile and recompile the benchmark code between cycles in order
   * to prevent periodic runtime optimizations from interfering with benchmark stats over the course
   * of a run.
  */
  [@bs.module "benchmark"] [@bs.scope ("Benchmark", "support")] external decompilation: bool = "decompilation";

};

module Times = {

  type t = times;

  [@bs.get] external cycle: t => float = "cycle";
  
  [@bs.get] external elapsed: t => float = "elapsed";
  
  [@bs.get] external period: t => float = "period";
  
  [@bs.get] external timeStamp: t => float = "timeStamp";
  
};

module Utils = {

  [@bs.module "benchmark"] [@bs.scope "Benchmark"] external formatNumber: float => string = "formatNumber";
  
  /**
   * [ filterBenchmarks(benchmarkArray, predicate) ]
   * Filters an array of benchmark objects based on the return value of the predicate function.
   */
  [@bs.module "benchmark"] [@bs.scope "Benchmark"] external filterBenchmarks: (array(benchmark), benchmark => bool) => array(benchmark) = "filter";

  [@bs.module "benchmark"] [@bs.scope "Benchmark"] external filterByFastest: (array(benchmark), [@bs.as "fastest"] _) => array(benchmark) = "filter";
  
  [@bs.module "benchmark"] [@bs.scope "Benchmark"] external filterBySlowest: (array(benchmark), [@bs.as "slowest"] _) => array(benchmark) = "filter";
  
  [@bs.module "benchmark"] [@bs.scope "Benchmark"] external filterBySuccessful: (array(benchmark), [@bs.as "successful"] _) => array(benchmark) = "filter";

};