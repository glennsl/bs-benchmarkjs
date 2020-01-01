/**
 * This top-level module defines the external types used in the API,
 * and then provides them to the API module functor, which in turn
 * provides them to the submodules.
 * 
 * This is useful for getting around the issue of circular module
 * references when type definitions need to be mutually or globally
 * visible across modules.
 */
module Types = {

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

  type eventType =  [
    | `abort
    | `complete
    | `cycle
    | `error
    | `reset
    | `start
    | `unknown
  ];

  let eventTypeFromString: string => eventType = fun
    | "abort" => `abort
    | "complete" => `complete
    | "cycle" => `cycle
    | "error" => `error
    | "reset" => `reset
    | "start" => `start
    | _ => `unknown;

  let eventTypeToString: eventType => string = fun
    | `abort => "abort"
    | `complete => "complete"
    | `cycle => "cycle"
    | `error => "error"
    | `reset => "reset"
    | `start => "start"
    | `unknown => "";

};

include Types;

module Benchmark = Glennsl__BsBenchmarkJs__Benchmark.Impl({
    type t = Types.benchmark;
    include Types;
  });

module Deferred =
  Glennsl__BsBenchmarkJs__Deferred.Impl({
    type t = Types.deferred;
    include Types;
  });

module Event =
  Glennsl__BsBenchmarkJs__Event.Impl({
    type t = Types.event;
    include Types;
  });

module Options =
  Glennsl__BsBenchmarkJs__Options.Impl({
    type t = Types.options;
    include Types;
  });

module Platform = Glennsl__BsBenchmarkJs__Platform.Impl({
  type t = Types.platform;
});

module Stats =
  Glennsl__BsBenchmarkJs__Stats.Impl({
    type t = Types.stats;
  });

module SuiteOptions =
  Glennsl__BsBenchmarkJs__SuiteOptions.Impl({
    type t = Types.suiteOptions;
    include Types;
  });

module Suite =
  Glennsl__BsBenchmarkJs__Suite.Impl({
    type t = Types.suite;
    include Types;
  });

module Support = Glennsl__BsBenchmarkJs__Support.Impl({
  type t = Types.support;
});

module Times =
  Glennsl__BsBenchmarkJs__Times.Impl({
    type t = Types.times;
    include Types;
  });

module Utils =
  Glennsl__BsBenchmarkJs__Utils.Impl({
    type benchmark = Types.benchmark;
  });