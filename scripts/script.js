recv("input", function (message) {
    var libraryName = Module.load(message.library).name;
    var onStartup = new NativeFunction(Module.getExportByName(libraryName, "onStartup"), "void", []);
    onStartup();
    send("done");
});
