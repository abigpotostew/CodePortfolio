#! /bin/bash
rm produce.db
python create_produce_table.py
python parse_produce.py produce.db regions/*
