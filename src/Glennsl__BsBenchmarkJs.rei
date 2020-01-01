module Types: {
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
    type eventType =
        [ `abort | `complete | `cycle | `error | `reset | `start | `unknown ];
    let eventTypeFromString: string => eventType;
    let eventTypeToString: eventType => string;
  };

type benchmark = Types.benchmark;
type suite = Types.suite;
type suiteOptions = Types.suiteOptions;
type deferred = Types.deferred;
type event = Types.event;
type options = Types.options;
type times = Types.times;
type stats = Types.stats;
type platform = Types.platform;
type support = Types.support;
type testFn = (. unit) => unit;
type setupFn = (. unit) => unit;
type teardownFn = (. unit) => unit;
type eventHandler = (. event) => unit;
type eventType = [ `abort | `complete | `cycle | `error | `reset | `start | `unknown ];
let eventTypeFromString: string => eventType;
let eventTypeToString: eventType => string;

module Benchmark:
  {
    let getAborted: Types.benchmark => bool;
    let getCompiled: Types.benchmark => (. unit) => unit;
    let getCycles: Types.benchmark => int;
    let getCount: Types.benchmark => int;
    let getError: Types.benchmark => Js.Null_undefined.t(Js.Exn.t);
    let getFn: Types.benchmark => (. unit) => unit;
    let getHz: Types.benchmark => float;
    let getRunning: Types.benchmark => bool;
    let getSetup: Types.benchmark => (. unit) => unit;
    let getStats: Types.benchmark => Types.stats;
    let getTeardown: Types.benchmark => (. unit) => unit;
    let getTime: Types.benchmark => Types.times;
    let getName: Types.benchmark => string;
    let getOptions: Types.benchmark => Types.options;
    let make: (~name: string=?, ~options: Types.options=?, (. unit) => unit) => Types.benchmark;
    let run: (~options: Types.options=?, Types.benchmark) => Types.benchmark;
  };

module Deferred:
  {
    let getBenchmark: Types.deferred => Types.benchmark;
    let getCycle: Types.deferred => float;
    let getElapsed: Types.deferred => float;
    let getTimeStamp: Types.deferred => float;
  };

module Event:
  {
    type eventType = [ `abort | `complete | `cycle | `error | `reset | `start | `unknown ];
    let eventTypeToString: [ `abort | `complete | `cycle | `error | `reset | `start | `unknown ] => string;
    let eventTypeFromString: string => [ `abort | `complete | `cycle | `error | `reset | `start | `unknown ];
    let make: eventType => Types.event;
    let fromEvent: Types.event => Types.event;
    let isAborted: Types.event => bool;
    let isCancelled: Types.event => bool;
    let currentTarget: Types.event => Types.benchmark;
    let target: Types.event => Types.benchmark;
    let timeStamp: Types.event => int;
  };

module Options:
  {
    let copy: Types.options => Types.options;
    let empty: unit => Types.options;
    let make:
      (~async: bool=?, ~defer: bool=?, ~delay: float=?, ~id: string=?,
      ~initCount: int=?, ~maxTime: float=?, ~minSamples: int=?,
      ~minTime: float=?, ~name: string=?,
      ~onAbort: (. Types.event) => unit=?,
      ~onComplete: (. Types.event) => unit=?,
      ~onCycle: (. Types.event) => unit=?,
      ~onError: (. Types.event) => unit=?,
      ~onReset: (. Types.event) => unit=?,
      ~onStart: (. Types.event) => unit=?, ~fn: (. unit) => unit=?,
      ~setup: (. unit) => unit=?, ~teardown: (. unit) => unit=?,
      ~queued: bool=?, unit) => Types.options;
    let update:
      (~async: bool=?, ~defer: bool=?, ~delay: float=?, ~id: string=?,
      ~initCount: int=?, ~maxTime: float=?, ~minSamples: int=?,
      ~minTime: float=?, ~name: string=?,
      ~onAbort: (. Types.event) => unit=?,
      ~onComplete: (. Types.event) => unit=?,
      ~onCycle: (. Types.event) => unit=?,
      ~onError: (. Types.event) => unit=?,
      ~onReset: (. Types.event) => unit=?,
      ~onStart: (. Types.event) => unit=?, ~fn: (. unit) => unit=?,
      ~setup: (. unit) => unit=?, ~teardown: (. unit) => unit=?,
      ~queued: bool=?, Types.options) => Types.options;
    let getAsync: Types.options => option(bool);
    let getDefer: Types.options => option(bool);
    let getDelay: Types.options => option(float);
    let getId: Types.options => option(string);
    let getInitCount: Types.options => option(int);
    let getMaxTime: Types.options => option(float);
    let getMinSamples: Types.options => option(int);
    let getMinTime: Types.options => option(float);
    let getName: Types.options => option(string);
    let getOnAbort: Types.options => option((. Types.event) => unit);
    let getOnComplete: Types.options => option((. Types.event) => unit);
    let getOnCycle: Types.options => option((. Types.event) => unit);
    let getOnError: Types.options => option((. Types.event) => unit);
    let getOnReset: Types.options => option((. Types.event) => unit);
    let getOnStart: Types.options => option((. Types.event) => unit);
    let getFn: Types.options => option((. unit) => unit);
    let getSetup: Types.options => option((. unit) => unit);
    let getTeardown: Types.options => option((. unit) => unit);
    let getQueued: Types.options => option(bool);
    let setAsync: (bool, Types.options) => Types.options;
    let setDefer: (bool, Types.options) => Types.options;
    let setDelay: (float, Types.options) => Types.options;
    let setId: (string, Types.options) => Types.options;
    let setInitCount: (int, Types.options) => Types.options;
    let setMaxTime: (float, Types.options) => Types.options;
    let setMinSamples: (int, Types.options) => Types.options;
    let setMinTime: (float, Types.options) => Types.options;
    let setName: (string, Types.options) => Types.options;
    let setOnAbort: ((. Types.event) => unit, Types.options) => Types.options;
    let setOnComplete: ((. Types.event) => unit, Types.options) => Types.options;
    let setOnCycle: ((. Types.event) => unit, Types.options) => Types.options;
    let setOnError: ((. Types.event) => unit, Types.options) => Types.options;
    let setOnReset: ((. Types.event) => unit, Types.options) => Types.options;
    let setOnStart: ((. Types.event) => unit, Types.options) => Types.options;
    let setFn: ((. unit) => unit, Types.options) => Types.options;
    let setSetup: ((. unit) => unit, Types.options) => Types.options;
    let setTeardown: ((. unit) => unit, Types.options) => Types.options;
    let setQueued: (bool, Types.options) => Types.options;
  };

module Platform:
  {
    module OS:
      {
        type t;
        let architecture: option(string);
        let family: option(string);
        let version: option(string);
        let toString: string;
      };
    let description: option(string);
    let layout: option(string);
    let product: option(string);
    let name: option(string);
    let manufacturer: option(string);
    let os: option(OS.t);
    let prerelease: option(string);
    let version: option(string);
    let toString: unit => string;
  };

module Stats:
  {
    let getDeviation: Types.stats => float;
    let getMean: Types.stats => float;
    let getMOE: Types.stats => float;
    let getRME: Types.stats => float;
    let getSample: Types.stats => array(float);
    let getSEM: Types.stats => float;
    let getVariance: Types.stats => float;
  };

module SuiteOptions:
  {
    let getName: Types.suiteOptions => option(string);
    let getOnAbort: Types.suiteOptions => option((. Types.event) => unit);
    let getOnComplete: Types.suiteOptions => option((. Types.event) => unit);
    let getOnCycle: Types.suiteOptions => option((. Types.event) => unit);
    let getOnError: Types.suiteOptions => option((. Types.event) => unit);
    let getOnReset: Types.suiteOptions => option((. Types.event) => unit);
    let getOnStart: Types.suiteOptions => option((. Types.event) => unit);
    let setName: (string, Types.suiteOptions) => Types.suiteOptions;
    let setOnAbort: ((. Types.event) => unit, Types.suiteOptions) => Types.suiteOptions;
    let setOnComplete: ((. Types.event) => unit, Types.suiteOptions) => Types.suiteOptions;
    let setOnCycle: ((. Types.event) => unit, Types.suiteOptions) => Types.suiteOptions;
    let setOnError: ((. Types.event) => unit, Types.suiteOptions) => Types.suiteOptions;
    let setOnReset: ((. Types.event) => unit, Types.suiteOptions) => Types.suiteOptions;
    let setOnStart: ((. Types.event) => unit, Types.suiteOptions) => Types.suiteOptions;
    let make:
      (~name: string=?, ~onAbort: (. Types.event) => unit=?,
      ~onComplete: (. Types.event) => unit=?,
      ~onCycle: (. Types.event) => unit=?,
      ~onError: (. Types.event) => unit=?,
      ~onReset: (. Types.event) => unit=?,
      ~onStart: (. Types.event) => unit=?, Types.suiteOptions) =>
      Types.suiteOptions;
  };

module Suite:
  {
    let getName: Types.suite => string;
    let getAborted: Types.suite => bool;
    let getLength: Types.suite => int;
    let getRunning: Types.suite => bool;
    let make: (~options: Types.suiteOptions=?, string) => Types.suite;
    let add: (~options: Types.options=?, string, (. unit) => unit, Types.suite) => Types.suite;
    let run: (~options: Types.suiteOptions=?, Types.suite) => Types.suite;
    let clone: (~options: Types.suiteOptions=?, Types.suite) => Types.suite;
    let filter: (Types.benchmark => bool, Types.suite) => Types.suite;
    let filterByName: (string, Types.suite) => Types.suite;
    let getListeners: Types.suite => array((. Types.event) => unit);
    let getListenersByEvent: ([ `abort | `complete | `cycle | `error | `reset | `start | `unknown ], Types.suite) => array((. Types.event) => unit);
    let emit: ([ `abort | `complete | `cycle | `error | `reset | `start | `unknown ], Types.suite) => Types.suite;
    let abort: Types.suite => Types.suite;
    let reset: Types.suite => Types.suite;
    let onAbort: ((. Types.event) => unit, Types.suite) => Types.suite;
    let onComplete: ((. Types.event) => unit, Types.suite) => Types.suite;
    let onCycle: ((. Types.event) => unit, Types.suite) => Types.suite;
    let onError: ((. Types.event) => unit, Types.suite) => Types.suite;
    let onReset: ((. Types.event) => unit, Types.suite) => Types.suite;
    let onStart: ((. Types.event) => unit, Types.suite) => Types.suite;
    let on:
      (list([ `abort
            | `complete
            | `cycle
            | `error
            | `reset
            | `start
            | `unknown ]),
      (. Types.event) => unit, Types.suite) => Types.suite;
    let removeListener:
      (list([ `abort
            | `complete
            | `cycle
            | `error
            | `reset
            | `start
            | `unknown ]),
      (. Types.event) => unit, Types.suite) => Types.suite;
    let removeListenersByEvent:
      (list([ `abort
            | `complete
            | `cycle
            | `error
            | `reset
            | `start
            | `unknown ]),
      Types.suite) => Types.suite;
    let removeAllListeners: Types.suite => Types.suite;
    let toArray: Types.suite => array(Types.benchmark);
    let toList: Types.suite => list(Types.benchmark);
    let fromArray: (~options: Types.suiteOptions=?, string, array(Types.benchmark)) => Types.suite;
    let fromList: (~options: Types.suiteOptions=?, string, list(Types.benchmark)) => Types.suite;
  };
  
module Support:
  {
    let browser: bool;
    let decompilation: bool;
    let timeout: bool;
  };

module Times:
  {
    let getCycle: Types.times => float;
    let getElapsed: Types.times => float;
    let getPeriod: Types.times => float;
    let getTimeStamp: Types.times => float;
  };

module Utils:
  {
    let formatFloat: float => string;
    let filterBenchmarks: (array(Types.benchmark), Types.benchmark => bool) => array(Types.benchmark);
    let filterByFastest: array(Types.benchmark) => array(Types.benchmark);
    let filterBySlowest: array(Types.benchmark) => array(Types.benchmark);
    let filterBySuccessful: array(Types.benchmark) => array(Types.benchmark);
  };