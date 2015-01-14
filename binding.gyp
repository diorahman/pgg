{ 
  "targets": [
    {
      "target_name": "pgg",
      "sources": [
        "src/pgg.cc", "src/pgg_obj.cc", "src/pgg_gpg.cc"
      ],
      "include_dirs": [
        "src", 
        "<!(node -e \"require('nan')\")" 
      ],
      "link_settings": {
        "libraries": [
          "-lgpgme",
          "-lgpg-error"
        ]
      }
    }
  ]
}
