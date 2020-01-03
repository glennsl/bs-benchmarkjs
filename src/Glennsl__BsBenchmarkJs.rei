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
let eventTypeFromString: string => eventType;
let eventTypeToString: eventType => string;

module Types: {
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
  type nonrec testFn = (. unit) => unit;
  type nonrec setupFn = (. unit) => unit;
  type nonrec teardownFn = (. unit) => unit;
  type nonrec eventHandler = (. event) => unit;
  type nonrec eventType = [ | `abort | `complete | `cycle | `error | `reset | `start | `unknown];
  let eventTypeFromString: string => eventType;
  let eventTypeToString: eventType => string;
};

module Benchmark: {
  let getAborted: benchmark => bool;
  let getCompiled: benchmark => (. unit) => unit;
  let getCycles: benchmark => int;
  let getCount: benchmark => int;
  let getError: benchmark => Js.Null_undefined.t(Js.Exn.t);
  let getFn: benchmark => (. unit) => unit;
  let getHz: benchmark => float;
  let getRunning: benchmark => bool;
  let getSetup: benchmark => (. unit) => unit;
  let getStats: benchmark => stats;
  let getTeardown: benchmark => (. unit) => unit;
  let getTime: benchmark => times;
  let getName: benchmark => string;
  let getOptions: benchmark => options;
  let make: (~name: string=?, ~options: options=?, (. unit) => unit) => benchmark;
  let run: (~options: options=?, benchmark) => benchmark;
};

module Deferred: {
  let getBenchmark: deferred => benchmark;
  let getCycle: deferred => float;
  let getElapsed: deferred => float;
  let getTimeStamp: deferred => float;
};

module Event: {
  type eventType = [ | `abort | `complete | `cycle | `error | `reset | `start | `unknown];
  let eventTypeToString:
    [ | `abort | `complete | `cycle | `error | `reset | `start | `unknown] => string;
  let eventTypeFromString:
    string => [ | `abort | `complete | `cycle | `error | `reset | `start | `unknown];
  let make: eventType => event;
  let fromEvent: event => event;
  let isAborted: event => bool;
  let isCancelled: event => bool;
  let currentTarget: event => benchmark;
  let target: event => benchmark;
  let timeStamp: event => int;
  let getType: event => string;
};

module Options: {

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
      ~onAbort: (. event) => unit=?,
      ~onComplete: (. event) => unit=?,
      ~onCycle: (. event) => unit=?,
      ~onError: (. event) => unit=?,
      ~onReset: (. event) => unit=?,
      ~onStart: (. event) => unit=?,
      ~fn: (. unit) => unit=?,
      ~setup: (. unit) => unit=?,
      ~teardown: (. unit) => unit=?,
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
      ~onAbort: (. event) => unit=?,
      ~onComplete: (. event) => unit=?,
      ~onCycle: (. event) => unit=?,
      ~onError: (. event) => unit=?,
      ~onReset: (. event) => unit=?,
      ~onStart: (. event) => unit=?,
      ~fn: (. unit) => unit=?,
      ~setup: (. unit) => unit=?,
      ~teardown: (. unit) => unit=?,
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
  
  let getOnAbort: options => option((. event) => unit);
  
  let getOnComplete: options => option((. event) => unit);
  
  let getOnCycle: options => option((. event) => unit);
  
  let getOnError: options => option((. event) => unit);
  
  let getOnReset: options => option((. event) => unit);
  
  let getOnStart: options => option((. event) => unit);
  
  let getFn: options => option((. unit) => unit);
  
  let getSetup: options => option((. unit) => unit);
  
  let getTeardown: options => option((. unit) => unit);
  
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
  
  let setOnAbort: ((. event) => unit, options) => options;
  
  let setOnComplete: ((. event) => unit, options) => options;
  
  let setOnCycle: ((. event) => unit, options) => options;
  
  let setOnError: ((. event) => unit, options) => options;
  
  let setOnReset: ((. event) => unit, options) => options;
  
  let setOnStart: ((. event) => unit, options) => options;
  
  let setFn: ((. unit) => unit, options) => options;
  
  let setSetup: ((. unit) => unit, options) => options;
  
  let setTeardown: ((. unit) => unit, options) => options;
  
  let setQueued: (bool, options) => options;
  
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
module Platform: {

  module OS: {
    
    type t;
    
    /** [ architecture ] The orchitecture of the operating system. */
    let architecture: option(string);
    
    /** [ family ] The operating system family. */
    let family: option(string);
    
    /** [ version ] The version name/number of the operating system. */
    let version: option(string);
    
    /** [ toString ] Returns the description of the OS, or an empty string if
     * the description is unavailable.
     */
    let toString: string;
    
  };

  /** [ description ] A short string describing the host operating system and runtime platform. */
  let description: option(string);

  /** [ layout ] The host platform's JS interpreter engine. E.g. "WebKit", "V8", "SpiderMonkey". */
  let layout: option(string);

  /** [ product ] The host device name. E.g. "iPad", "Android Galaxy S3". */
  let product: option(string);
  
  /** [ name ] The name of the host platfrom or browser. E.g. "Safari", "Node", "Firefox". */
  let name: option(string);
  
  /** [ manufacturer ] The name of the device manufacturer. E.g. "HP", "Apple", "Microsoft". */
  let manufacturer: option(string);
  
  /** [ os ] The name of the host operating system. E.g. "Ubuntu 18.04". */
  let os: option(OS.t);
  
  /** [ prerelease ] The aplph/beta release indicator. */
  let prerelease: option(string);
  
  /** [ version ] The version of the host operating system. */
  let version: option(string);
  
  /** [ toString() ] Returns the [ description ] property (string) or an empty string if the description is not available. */
  let toString: unit => string;

};

module Stats: {

  /** [ getDeviation(stats) ] Returns the standard deviation of the sample. */
  let getDeviation: stats => float;

  /** [ getMean(stats) ] Returns the mean of the sample. */
  let getMean: stats => float;

  /** [ getMOE(stats) ] Returns the margin of error of the sample. */
  let getMOE: stats => float;

  /** [ getRME(stats) ] Returns the relative margin of error of the sample. */
  let getRME: stats => float;

  /** [ getSample(stats) ] Returns an array of sampled time periods. */
  let getSample: stats => array(float);
  
  /** [ getSEM(stats) ] Returns the standard error of the mean of the sample. */
  let getSEM: stats => float;
  
  /** [ getVariance(stats) ] Returns the variance of the sample. */
  let getVariance: stats => float;
  
};

module SuiteOptions: {

  let getName: suiteOptions => option(string);

  let getOnAbort: suiteOptions => option((. event) => unit);

  let getOnComplete: suiteOptions => option((. event) => unit);

  let getOnCycle: suiteOptions => option((. event) => unit);

  let getOnError: suiteOptions => option((. event) => unit);

  let getOnReset: suiteOptions => option((. event) => unit);

  let getOnStart: suiteOptions => option((. event) => unit);

  let setName: (string, suiteOptions) => suiteOptions;

  let setOnAbort: ((. event) => unit, suiteOptions) => suiteOptions;

  let setOnComplete: ((. event) => unit, suiteOptions) => suiteOptions;

  let setOnCycle: ((. event) => unit, suiteOptions) => suiteOptions;

  let setOnError: ((. event) => unit, suiteOptions) => suiteOptions;

  let setOnReset: ((. event) => unit, suiteOptions) => suiteOptions;

  let setOnStart: ((. event) => unit, suiteOptions) => suiteOptions;

  let make:
    (
      ~name: string=?,
      ~onAbort: (. event) => unit=?,
      ~onComplete: (. event) => unit=?,
      ~onCycle: (. event) => unit=?,
      ~onError: (. event) => unit=?,
      ~onReset: (. event) => unit=?,
      ~onStart: (. event) => unit=?,
      suiteOptions
    ) =>
    suiteOptions;

};

module Suite: {

  type t = suite;

  /**
   * [ getName(suite) ]
   * Returns the name of the suite instance.
   */
  let getName: suite => string;

  /**
   * [ getAborted(suite) ]
   * Returns true if the suite was aborted during a run.
   */
  let getAborted: suite => bool;

  /**
   * [ getLength(suite) ]
   * Returns the number of benchmark instances in the suite.
   */
  let getLength: suite => int;

  /**
   * [ getRunning(suite) ]
   * Returns true if the suite is currently running.
   */
  let getRunning: suite => bool;

  /**
   * [ make(~options=?, name) ]
   * Creates a new suite instance.
   */
  let make: (~options: suiteOptions=?, string) => suite;

  /**
   * [ add(~options=?, name, testFn) ]
   * Creates a new Benchmark.t from the provided arguments, adds it
   * to the suite instance, and returns the suite.
   */
  let add: (~options: options=?, string, (. unit) => unit, suite) => suite;

  /**
   * [ run(~options=?, suite) ]
   * Runs all the benchmark functions in the suite, and returns the suite.
   */
  let run: (~options: suiteOptions=?, suite) => suite;

  /**
   * [ clone(~options=?, suite) ]
   * Returns a clone of the suite.
   */
  let clone: (~options: suiteOptions=?, suite) => suite;

  /**
   * [ filter(predicate, suite) ]
   * Filters the benchmarks in the suite based on the [predicate] function,
   * returning a new suite.
   */
  let filter: (benchmark => bool, suite) => suite;

  /**
   * [ filterByFastest(name, suite) ]
   * Returns a new suite containing only the fastest benchmarks.
   */
  let filterByFastest: suite => suite;

  /**
   * [ filterBySlowest(name, suite) ]
   * Returns a new suite containing only the slowest benchmarks.
   */
  let filterBySlowest: suite => suite;

  /**
   * [ filterBySuccessful(name, suite) ]
   * Returns a new suite containing only the successful benchmarks.
   */
  let filterBySuccessful: suite => suite;

  /**
   * [ getListeners(suite) ]
   * Returns an array of all the event listener functions that are listening
   * to the suite's events.
   */
  let getListeners: suite => array((. event) => unit);

  /**
   * [ getListenersByEvent(suite) ]
   * Returns an array of even listeners that are listeneng to the specified
   * event type.
   */
  let getListenersByEvent:
    ([ | `abort | `complete | `cycle | `error | `reset | `start | `unknown], suite) =>
    array((. event) => unit);

  /**
   * [ emit(eventType) ]
   * Calls each of the suite's event listeners that are listening to
   * the specified event type.
   */
  let emit:
    ([ | `abort | `complete | `cycle | `error | `reset | `start | `unknown], suite) => suite;

  /**
   * [ abort(suite) ] Aborts the suite if it is currently running.
   */
  let abort: suite => suite;

  /**
   * [ reset(suite) ]
   * Resets the suite.
   */
  let reset: suite => suite;

  /**
   * [ onAbort(eventListener, suite) ]
   * Adds an event listener to the suite.
   */
  let onAbort: ((. event) => unit, suite) => suite;

  /**
   * [ onAbort(eventListener, suite) ]
   * Adds an event listener to the suite.
   */
  let onComplete: ((. event) => unit, suite) => suite;

  /**
   * [ onAbort(eventListener, suite) ]
   * Adds an event listener to the suite.
   */
  let onCycle: ((. event) => unit, suite) => suite;

  /**
   * [ onAbort(eventListener, suite) ]
   * Adds an event listener to the suite.
   */
  let onError: ((. event) => unit, suite) => suite;

  /**
   * [ onAbort(eventListener, suite) ]
   * Adds an event listener to the suite.
   */
  let onReset: ((. event) => unit, suite) => suite;

  /**
   * [ onAbort(eventListener, suite) ]
   * Adds an event listener to the suite.
   */
  let onStart: ((. event) => unit, suite) => suite;

  /**
   * [ onAbort(eventListener, suite) ]
   * Adds an event listener to the suite. This function allows you specify a
   * list of events that the listener will respond to.
   */
  let on:
    (
      list([ | `abort | `complete | `cycle | `error | `reset | `start | `unknown]),
      (. event) => unit,
      suite
    ) =>
    suite;

  /**
   * [ removeListener(eventList, eventListener, suite) ]
   * Removes an event listener from the suite. The function is identified by
   * a physical (reference) equality check, so the exact reference must
   * be provided, along with the event type(s) it is listening to.
   */
  let removeListener:
    (
      list([ | `abort | `complete | `cycle | `error | `reset | `start | `unknown]),
      (. event) => unit,
      suite
    ) =>
    suite;

  /**
   * [ removeListenersByEvent(eventList, suite) ]
   * Removes all event listeners from the suite which correspond to the
   * specified events, and returns the suite.
   */
  let removeListenersByEvent:
    (list([ | `abort | `complete | `cycle | `error | `reset | `start | `unknown]), suite) => suite;

  /**
   * [ removeAllListeners(suite) ]
   * Removes all the event listeners from the suite and returns the suite.
   */
  let removeAllListeners: suite => suite;

  /**
   * [ toArray(suite) ]
   * Returns an array of all the benchmarks that are currently assigned to the suite.
   */
  let toArray: suite => array(benchmark);

  /**
   * [ toList(suite) ]
   * Returns an list of all the benchmarks that are currently assigned to the suite.
   */
  let toList: suite => list(benchmark);

  /**
   * [ fromArray(~options=?, name, benchmarkArray) ]
   * Takes an array of benchmarks and adds them all to a new suite instance.
   */
  let fromArray: (~options: suiteOptions=?, string, array(benchmark)) => suite;

  /**
   * [ fromArray(~options=?, name, benchmarkList) ]
   * Takes a list of benchmarks and adds them all to a new suite instance.
   */
  let fromList: (~options: suiteOptions=?, string, list(benchmark)) => suite;
};

/**
 * [ Support ]
 *
 * An object used internally by Benchmark.js which is inspected
 * to determine the presence of certain runtime features. Those features
 * affect the way Benchmark.js handles certain things, like async
 * benchmarking, and function decompilation.
 *
 * Decompilation can be used to thwart runtime optimizations over
 * the course of sampling a test case, possibly improvint the reliability
 * of the results.
 */
module Support: {
  let browser: bool;
  let decompilation: bool;
  let timeout: bool;
};

module Times: {
  let getCycle: times => float;
  let getElapsed: times => float;
  let getPeriod: times => float;
  let getTimeStamp: times => float;
};

module Utils: {
  let formatFloat: float => string;
  let filterBenchmarks: (array(benchmark), benchmark => bool) => array(benchmark);
  let filterByFastest: array(benchmark) => array(benchmark);
  let filterBySlowest: array(benchmark) => array(benchmark);
  let filterBySuccessful: array(benchmark) => array(benchmark);
};