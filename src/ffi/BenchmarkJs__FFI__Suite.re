module Impl =
       (
         T: {
           type t;
           type benchmark;
           type suiteOptions;
           type options;
           type event;
           type eventHandler;
           type testFn;
           type setupFn;
         },
       ) => {
  [@bs.module "benchmark"] [@bs.scope "Benchmark"] [@bs.new] external make: string => T.t = "Suite";
  [@bs.module "benchmark"] [@bs.scope "Benchmark"] [@bs.new]
  external makeWithOptions: (string, T.suiteOptions) => T.t = "Suite";
  // instance properties
  [@bs.get] external getAborted: T.t => bool = "aborted";
  [@bs.get] external getLength: T.t => int = "length";
  [@bs.get] external getRunning: T.t => bool = "running";
  [@bs.get] [@bs.scope "options"] external getName: T.t => string = "name";
  // instance methods
  [@bs.send.pipe: T.t] external add: (string, T.testFn) => T.t = "add";
  [@bs.send.pipe: T.t] external addWithOptions: (string, T.testFn, T.options) => T.t = "add";

  module Add_withArgs = {
    [@bs.send.pipe: T.t] external name_fn_options: (string, T.testFn, T.options) => T.t = "add";
    [@bs.send.pipe: T.t] external name_fn: (string, T.testFn) => T.t = "add";
    [@bs.send.pipe: T.t] external name_options: (string, T.options) => T.t = "add";
    [@bs.send.pipe: T.t] external fn: T.testFn => T.t = "add";
    [@bs.send.pipe: T.t] external fn_options: (T.testFn, T.options) => T.t = "add";
    [@bs.send.pipe: T.t] external options: T.options => T.t = "add";
  };

  [@bs.send.pipe: T.t] external run: T.t = "run";
  [@bs.send.pipe: T.t] external runWithOptions: T.suiteOptions => T.t = "run";

  [@bs.send.pipe: T.t] external filter: (T.benchmark => bool) => T.t = "filter";
  [@bs.send.pipe: T.t] external filterByName: string => T.t = "filter";

  [@bs.send.pipe: T.t] external getListeners: array(T.eventHandler) = "listeners";
  [@bs.send.pipe: T.t] external getListenersByEvent: string => array(T.eventHandler) = "listeners";

  [@bs.send.pipe: T.t] external emit: string => T.t = "emit";
  [@bs.send.pipe: T.t] external emitFromEvent: T.event => T.t = "emit";

  [@bs.send.pipe: T.t] external removeListener: (string, T.eventHandler) => T.t = "off";
  [@bs.send.pipe: T.t] external removeListenersByEvent: string => T.t = "off";
  [@bs.send.pipe: T.t] external removeAllListeners: T.t = "off";

  [@bs.send.pipe: T.t] external clone: T.t = "clone";
  [@bs.send.pipe: T.t] external cloneWithOptions: T.suiteOptions => T.t = "clone";

  [@bs.send.pipe: T.t] external on: (string, T.eventHandler) => T.t = "on";

  [@bs.send.pipe: T.t] external abort: T.t = "abort";
  [@bs.send.pipe: T.t] external reset: T.t = "reset";

  [@bs.val] [@bs.scope ("Array", "prototype", "slice")]
  external toBenchmarkArray: T.t => array(T.benchmark) = "call";
};

type t = BenchmarkJs__Types.suite;

include Impl({
  type nonrec t = t;
  type benchmark = BenchmarkJs__Types.benchmark;
  type suiteOptions = BenchmarkJs__Types.suiteOptions;
  type options = BenchmarkJs__Types.options;
  type event = BenchmarkJs__Types.event;
  type eventHandler = BenchmarkJs__Types.eventHandler;
  type testFn = BenchmarkJs__Types.testFn;
  type setupFn = BenchmarkJs__Types.setupFn;
});