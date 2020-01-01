/**
 * All of the API submodules are implemented via functors to provide the
 * type definitions from the top level downward. This particular module
 * functor acts as a routing point for all type definitions to flow to
 * those submodule functors.
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

  module Benchmark = Glennsl__BsBenchmarkJs__Benchmark;
  module Deferred = Glennsl__BsBenchmarkJs__Deferred;
  module Event = Glennsl__BsBenchmarkJs__Event;
  module Options = Glennsl__BsBenchmarkJs__Options;
  module Platform = Glennsl__BsBenchmarkJs__Platform;
  module Stats = Glennsl__BsBenchmarkJs__Stats;
  module SuiteOptions = Glennsl__BsBenchmarkJs__SuiteOptions;
  module Suite = Glennsl__BsBenchmarkJs__Suite;
  module Support = Glennsl__BsBenchmarkJs__Support;
  module Times = Glennsl__BsBenchmarkJs__Times;
  module Utils = Glennsl__BsBenchmarkJs__Utils;

};





// module Impl =
//        (
//          T: {
//            type benchmark;
//            type suite;
//            type suiteOptions;
//            type deferred;
//            type event;
//            type options;
//            type times;
//            type stats;
//            type platform;
//            type support;
//            type eventType;
//            type eventHandler;
//            type testFn;
//            type setupFn;
//            type teardownFn;
//            let eventTypeToString: eventType => string;
//            let eventTypeFromString: string => eventType;
//          },
//        ) => {

//   module Benchmark =
//     Benchmark.Impl({
//       type t = T.benchmark;
//       include T;
//     });

//   module Deferred =
//     Deferred.Impl({
//       type t = T.deferred;
//       include T;
//     });

//   module Event =
//     Event.Impl({
//       type t = T.event;
//       include T;
//     });

//   module Options =
//     Options.Impl({
//       type t = T.options;
//       include T;
//     });

//   module Platform = Platform.Impl({
//     type t = T.platform;
//   });

//   module Stats =
//     Stats.Impl({
//       type t = T.stats;
//     });

//   module SuiteOptions =
//     SuiteOptions.Impl({
//       type t = T.suiteOptions;
//       include T;
//     });

//   module Suite =
//     Suite.Impl({
//       type t = T.suite;
//       include T;
//     });

//   module Support = Support.Impl({
//     type t = T.support;
//   });

//   module Times =
//     Times.Impl({
//       type t = T.times;
//       include T;
//     });

//   module Utils =
//     Utils.Impl({
//       type benchmark = T.benchmark;
//     });
// };