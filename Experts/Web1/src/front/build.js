const esbuild = require('esbuild');

esbuild.build({
  entryPoints: [
    'src/index.ts',
  ],
  outfile: 'public/js/components.js',
  format: 'esm', // Use ESM format for module support
  bundle: true, 
  minify: true,
}).catch(() => process.exit(1));

